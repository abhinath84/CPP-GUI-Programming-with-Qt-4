#include "CGPlotter.h"
#include "CGPlotSettings.h"

#include <QtGui>
#include <cmath>
#include <QToolButton>
#include <QStylePainter>
#include <QStyleOptionFocusRect>

CGPlotter::CGPlotter(QWidget *parent)
    :QWidget(parent)
{
    /*
     * The setBackgroundRole() call tells QWidget to use the “dark” component of the
     * palette as the color for erasing the widget, instead of the “window” component.
     * This gives Qt a default color that it can use to fill any newly revealed pixels
     * when the widget is resized to a larger size, before paintEvent() even has the
     * chance to paint the new pixels. We also need to call setAutoFillBackground(true)
     * to enable this mechanism.
     * (By default, child widgets inherit the back-ground from their parent widget.)
    */
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);

    /*
     * The setSizePolicy() call sets the widget’s size policy to QSizePolicy::Expanding
     * in both directions. This tells any layout manager that is responsible for the
     * widget that the widget is especially willing to grow, but can also shrink. This
     * setting is typical for widgets that can take up a lot of screen space. The default
     * is QSizePolicy::Preferred in both directions, which means that the widget
     * prefers to be the size of its size hint, but it can be shrunk down to its minimum
     * size hint or expanded indefinitely if necessary.
    */
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*
     * The setFocusPolicy(Qt::StrongFocus) call makes the widget accept focus by
     * clicking or by pressing Tab . When the Plotter has focus, it will receive events
     * for key presses. The Plotter widget understands a few keys: + to zoom in; -
     * zoom out; and the arrow keys to scroll up, down, left, and right.
    */
    setFocusPolicy(Qt::StrongFocus);
    rubberBandIsShown = false;

    /*
     * The adjustSize() calls on the buttons set their sizes to be that of their size
     * hints. The buttons are not put in a layout; instead, we will position them
     * manually in the Plotter ’s resize event. Since we are not using any layouts, we must
     * specify the buttons’ parent explicitly by passing this to the QPushButton constructor.
    */
    tlbtnZoomIn = new QToolButton(this);
    tlbtnZoomIn->setIcon(QIcon(":/images/zoomin.png"));
    tlbtnZoomIn->adjustSize();
    connect(tlbtnZoomIn, SIGNAL(clicked()), this, SLOT(zoomIn()));

    tlbtnZoomOut = new QToolButton(this);
    tlbtnZoomOut->setIcon(QIcon(":/images/zoomout.png"));
    tlbtnZoomOut->adjustSize();
    connect(tlbtnZoomOut, SIGNAL(clicked()), this, SLOT(zoomOut()));

    /*
     * After the call to setPlotSettings() , the zoom stack contains only one entry, and
     * the Zoom In and Zoom Out buttons are hidden. These buttons will not be shown
     * until we call show() on them in the zoomIn() and zoomOut() slots. (Normally, it
     * is sufficient to call show() on the top-level widget to show all the children. But
     * when we explicitly call hide() on a child widget, it is hidden until we call show() on it.)
    */
    setPlotSettings(CGPlotSettings());
}

/*
 * The setPlotSettings() function is used to specify the CGPlotSettings to use for
 * displaying the plot. It is called by the Plotter constructor and can be called by
 * users of the class. The plotter starts out at its default zoom level. Each time
 * the user zooms in, a new CGPlotSettings instance is created and put onto the zoom stack.
*/
void CGPlotter::setPlotSettings(const CGPlotSettings &settings)
{
    zoomStack.clear();
    zoomStack.append(settings);
    curZoom = 0;
    tlbtnZoomIn->hide();
    tlbtnZoomOut->hide();

    /*
     * The call to refreshPixmap() is necessary to update the display. Usually, we
     * would call update() , but here we do things slightly differently because we
     * want to keep a QPixmap up to date at all times. After regenerating the pixmap,
     * refreshPixmap() calls update() to copy the pixmap onto the widget.
    */
    refreshPixmap();
}

/*
 * The zoomOut() slot zooms out if the graph is zoomed in. It decrements the
 * current zoom level and enables the Zoom Out button depending on whether the
 * graph can be zoomed out any more or not. The Zoom In button is enabled and
 * shown, and the display is updated with a call to refreshPixmap() .
*/
void CGPlotter::zoomOut()
{
    if (curZoom > 0)
    {
        --curZoom;
        tlbtnZoomOut->setEnabled(curZoom > 0);
        tlbtnZoomIn->setEnabled(true);
        tlbtnZoomIn->show();

        refreshPixmap();
    }
}

/*
 * If the user has previously zoomed in and then out again, the CGPlotSettings for
 * the next zoom level will be in the zoom stack, and we can zoom in. (Otherwise,
 * it is still possible to zoom in using a rubber band.)
 * The slot increments curZoom to move one level deeper into the zoom stack, sets
 * the Zoom In button enabled or disabled depending on whether it’s possible to
 * zoom in any further, and enables and shows the Zoom Out button. Again, we
 * call refreshPixmap() to make the plotter use the latest zoom settings.
*/
void CGPlotter::zoomIn()
{
    if (curZoom < zoomStack.count() - 1)
    {
        ++curZoom;
        tlbtnZoomIn->setEnabled(curZoom < zoomStack.count() - 1);
        tlbtnZoomOut->setEnabled(true);
        tlbtnZoomOut->show();

        refreshPixmap();
    }
}

/*
 * The setCurveData() function sets the curve data for a given curve ID. If a
 * curve with the same ID already exists in curveMap , it is replaced with the new
 * curve data; otherwise, the new curve is simply inserted. The curveMap member
 * variable is of type QMap<int, QVector<QPointF> > .
*/
void CGPlotter::setCurveData(int id, const QVector<QPointF> &data)
{
    curveMap[id] = data;
    refreshPixmap();
}

/*
 * The clearCurve() function removes the specified curve from the curve map.
*/
void CGPlotter::clearCurve(int id)
{
    curveMap.remove(id);
    refreshPixmap();
}

/*
 * The minimumSizeHint() function is similar to sizeHint() ; just as sizeHint()
 * specifies a widget’s ideal size, minimumSizeHint() specifies a widget’s ideal minimum
 * size. A layout never resizes a widget below its minimum size hint.
 * The value we return is 300 × 200 (since Margin equals 50) to allow for the margin
 * on all four sides and some space for the plot itself. Below that size, the plot
 * would be too small to be useful.
*/
QSize CGPlotter::minimumSizeHint() const
{
    return QSize(6 * Margin, 4 * Margin);
}

/*
 * In sizeHint() , we return an “ideal” size in proportion to the Margin constant and
 * with the same pleasing 3:2 aspect ratio we used for the minimumSizeHint() .
*/
QSize CGPlotter::sizeHint() const
{
    return QSize(12 * Margin, 8 * Margin);
}

/*
 * Normally, paintEvent() is the place where we perform all the drawing. But here
 * all the plot drawing is done beforehand in refreshPixmap() , so we can render the
 * entire plot simply by copying the pixmap onto the widget at position (0, 0).
*/
void CGPlotter::paintEvent(QPaintEvent * /* event */)
{
    /*
     * When we want to paint using the current style, we can use a QStylePainter
     * instead of a normal QPainter , as we have done in Plotter, and paint
     * more conveniently using that.
     * QStylePainter ’s drawPrimitive() function calls the QStyle function
     * of the same name, which can be used for drawing “primitive elements” like
     * panels, buttons, and focus rectangles. The widget style is usually the same for
     * all widgets in an application ( QApplication::style() ), but it can be overridden
     * on a per-widget basis using QWidget::setStyle() .
    */
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pixmap);

    /*
     * If the rubber band is visible, we draw it on top of the plot. We use the “light”
     * component from the widget’s current color group as the pen color to ensure
     * good contrast with the “dark” background. Notice that we draw directly on the
     * widget, leaving the off-screen pixmap untouched. Using QRect::normalized()
     * ensures that the rubber band rectangle has positive width and height
     * (swapping coordinates if necessary), and adjusted() reduces the size of the rectangle
     * by one pixel to allow for its own 1-pixel-wide outline.
    */
    if (rubberBandIsShown)
    {
        painter.setPen(palette().light().color());
        painter.drawRect(rubberBandRect.normalized().adjusted(0, 0, -1, -1));
    }

    /*
     * If the Plotter has focus, a focus rectangle is drawn using the widget style’s drawPrimitive()
     * function with QStyle::PE_FrameFocusRect as its first argument and
     * a QStyleOptionFocusRect object as its second argument. The focus rectangle’s
     * drawing options are inherited from the Plotter widget (by the initFrom() call).
     * The background color must be specified explicitly.
    */
    if (hasFocus())
    {
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().dark().color();
        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
    }
}

/*
 * Whenever the Plotter widget is resized, Qt generates a “resize” event. Here, we
 * reimplement resizeEvent() to place the Zoom In and Zoom Out buttons at the top
 * right of the Plotter widget.
 * We move the Zoom In button and the Zoom Out button to be side by side, separated
 * by a 5-pixel gap and with a 5-pixel offset from the top and right edges of
 * the parent widget.
 * If we wanted the buttons to stay rooted to the top-left corner, whose coordinates
 * are (0, 0), we would simply have moved them there in the Plotter constructor.
 * But we want to track the top-right corner, whose coordinates depend on the size
 * of the widget. Because of this, it’s necessary to reimplement resizeEvent() and
 * to set the buttons’ position there.
*/
void CGPlotter::resizeEvent(QResizeEvent * /* event */)
{
    int x = width() - (tlbtnZoomIn->width()
                        + tlbtnZoomOut->width() + 10);
    tlbtnZoomIn->move(x, 5);
    zoomOutButton->move(x + tlbtnZoomIn->width() + 5, 5);

    refreshPixmap();
}

/*
 * When the user presses the left mouse button, we start displaying a rubberband.
 * This involves setting rubberBandIsShown to true , initializing the rubberBandRect
 * member variable with the current mouse pointer position, scheduling
 * a paint event to paint the rubber band, and changing the mouse cursor to have
 * a crosshair shape.
 * The rubberBandRect variable is of type QRect . A QRect can be defined either as an
 * (x, y, width, height) quadruple—where (x, y) is the position of the top-left corner
 * and width × height is the size of the rectangle—or as a top-left and a bottom-right
 * coordinate pair. Here, we have used the coordinate pair representation.
 * We set the point where the user clicked as both the top-left corner and as the
 * bottom-right corner. Then we call updateRubberBandRegion() to force a repaint
 * of the (tiny) area covered by the rubber band.
*/
void CGPlotter::mousePressEvent(QMouseEvent *event)
{
    QRect rect(Margin, Margin,
                width() - 2 * Margin, height() - 2 * Margin);
    if (event->button() == Qt::LeftButton)
    {
        if (rect.contains(event->pos()))
        {
            rubberBandIsShown = true;
            rubberBandRect.setTopLeft(event->pos());
            rubberBandRect.setBottomRight(event->pos());
            updateRubberBandRegion();
            setCursor(Qt::CrossCursor);
        }
    }
}

/*
 * When the user moves the mouse cursor while holding the left button, we first
 * call updateRubberBandRegion() to schedule a paint event to repaint the area
 * where the rubber band was, then we recompute rubberBandRect to account for
 * the mouse move, and finally we call updateRubberBandRegion() a second time to
 * repaint the area where the rubber band has moved to. This effectively erases
 * the rubber band and redraws it at the new coordinates.
 * If the user moves the mouse upward or leftward, it’s likely that rubberBandRect’s
 * nominal bottom-right corner will end up above or to the left of its top-leftcorner.
 * If this occurs, the QRect will have a negative width or height. We used
 * QRect::normalized() in paintEvent() to ensure that the top-left and bottom-right
 * coordinates are adjusted to obtain a nonnegative width and height.
*/
void CGPlotter::mouseMoveEvent(QMouseEvent *event)
{
    if (rubberBandIsShown)
    {
        updateRubberBandRegion();
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
    }
}

/*
 * When the user moves the mouse cursor while holding the left button, we first
 * call updateRubberBandRegion() to schedule a paint event to repaint the area
 * where the rubber band was, then we recompute rubberBandRect to account for
 * the mouse move, and finally we call updateRubberBandRegion() a second time to
 * repaint the area where the rubber band has moved to. This effectively erases
 * the rubber band and redraws it at the new coordinates.
 * If the user moves the mouse upward or leftward, it’s likely that rubberBandRect’s
 * nominal bottom-right corner will end up above or to the left of its top-left
 * corner. If this occurs, the QRect will have a negative width or height. We used
 * QRect::normalized() in paintEvent() to ensure that the top-left and bottom-right
 * coordinates are adjusted to obtain a nonnegative width and height.
 * The code to perform the zoom is a bit complicated. This is because we deal with
 * widget coordinates and plotter coordinates at the same time. Most of the work
 * we perform here is to convert the rubberBandRect from widget coordinates to
 * plotter coordinates. Once we have done the conversion, we call CGPlotSettings::adjust()
 * to round the numbers and find a sensible number of ticks for each
 * axis. Figures 5.10 and 5.11 depict the situation.
*/
void CGPlotter::mouseReleaseEvent(QMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton) && rubberBandIsShown)
    {
        rubberBandIsShown = false;
        updateRubberBandRegion();
        unsetCursor();

        QRect rect = rubberBandRect.normalized();
        if (rect.width() < 4 || rect.height() < 4)
            return;

        rect.translate(-Margin, -Margin);
        CGPlotSettings prevSettings = zoomStack[curZoom];
        CGPlotSettings settings;
        double dx = prevSettings.spanX() / (width() - 2 * Margin);
        double dy = prevSettings.spanY() / (height() - 2 * Margin);
        settings.minX = prevSettings.minX + dx * rect.left();
        settings.maxX = prevSettings.minX + dx * rect.right();
        settings.minY = prevSettings.maxY - dy * rect.bottom();
        settings.maxY = prevSettings.maxY - dy * rect.top();
        settings.adjust();

        zoomStack.resize(curZoom + 1);
        zoomStack.append(settings);
        zoomIn();
    }
}
/*
 * When the user presses a key and the Plotter widget has focus, the keyPressEvent()
 * function is called. We reimplement it here to respond to six keys: + , -,
 * Up , Down , Left , and Right . If the user pressed a key that we are not handling, we
 * call the base class implementation. For simplicity, we ignore the Shift , Ctrl , and
 * Alt modifier keys, which are available through QKeyEvent::modifiers() .
*/
void CGPlotter::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Plus:
            zoomIn();
            break;
        case Qt::Key_Minus:
            zoomOut();
            break;
        case Qt::Key_Left:
            zoomStack[curZoom].scroll(-1, 0);
            refreshPixmap();
            break;
        case Qt::Key_Right:
            zoomStack[curZoom].scroll(+1, 0);
            refreshPixmap();
            break;
        case Qt::Key_Down:
            zoomStack[curZoom].scroll(0, -1);
            refreshPixmap();
            break;
        case Qt::Key_Up:
            zoomStack[curZoom].scroll(0, +1);
            refreshPixmap();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

/*
 * Wheel events occur when a mouse wheel is turned. Most mice only provide
 * a vertical wheel, but some also have a horizontal wheel. Qt supports both
 * kinds of wheel. Wheel events go to the widget that has the focus. The delta()
 * function returns the distance the wheel was rotated in eighths of a degree.
 * Mice typically work in steps of 15 degrees. Here, we scroll by the requested
 * number of ticks by modifying the topmost item on the zoom stack and update
 * the display using refreshPixmap() .
 * The most common use of the wheel mouse is to scroll a scroll bar. When we use
 * QScrollArea (covered in Chapter 6) to provide scroll bars, QScrollArea handles
 * the wheel mouse events automatically, so we don’t need to reimplement
 * wheelEvent() ourselves.
*/
void CGPlotter::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;
    int numTicks = numDegrees / 15;

    if (event->orientation() == Qt::Horizontal)
        zoomStack[curZoom].scroll(numTicks, 0);
    else
        zoomStack[curZoom].scroll(0, numTicks);

    refreshPixmap();
}

/*
 * The updateRubberBand() function is called from mousePressEvent() , mouseMoveEvent(),
 * and mouseReleaseEvent() to erase or redraw the rubber band. It consists
 * of four calls to update() that schedule a paint event for the four small rectangular
 * areas that are covered by the rubber band (two vertical and two horizontallines).
 * Qt provides the QRubberBand class for drawing rubber bands, but here,
 * hand-coding provided finer control.
*/
void CGPlotter::updateRubberBandRegion()
{
    QRect rect = rubberBandRect.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);
    update(rect.left(), rect.top(), 1, rect.height());
    update(rect.left(), rect.bottom(), rect.width(), 1);
    update(rect.right(), rect.top(), 1, rect.height());
}

/*
 * The refreshPixmap() function redraws the plot onto the off-screen pixmap and
 * updates the display. We resize the pixmap to have the same size as the widget
 * and fill it with the widget’s erase color. This color is the “dark” component of
 * the palette, because of the call to setBackgroundRole() in the Plotter constructor.
 * If the background is a non-solid brush, QPixmap::fill() needs to know the offset
 * in the widget where the pixmap will end up to align the brush pattern correctly.
 * Here, the pixmap corresponds to the entire widget, so we specify position (0, 0).
 *
 * Then we create a QPainter to draw on the pixmap. The initFrom() call sets the
 * painter’s pen, background, and font to the same ones as the Plotter widget.
 * Next we call drawGrid() and drawCurves() to perform the drawing. At the end,
 * we call update() to schedule a paint event for the whole widget. The pixmap is
 * copied to the widget in the paintEvent() function.
*/
void CGPlotter::refreshPixmap()
{
    pixmap = QPixmap(size());
    pixmap.fill(this, 0, 0);

    QPainter painter(&pixmap);
    painter.initFrom(this);
    drawGrid(&painter);
    drawCurves(&painter);
    update();
}

/*
 * The drawGrid() function draws the grid behind the curves and the axes. The
 * area on which we draw the grid is specified by rect . If the widget isn’t large
 * enough to accommodate the graph, we return immediately.
 * The first for loop draws the grid’s vertical lines and the ticks along the x axis.
 * The second for loop draws the grid’s horizontal lines and the ticks along the
 * y axis. At the end, we draw a rectangle along the margins. The drawText()
 * function is used to draw the numbers corresponding to the tick marks on
 * both axes.
*/
void CGPlotter::drawGrid(QPainter *painter)
{
    QRect rect(Margin, Margin,
                width() - 2 * Margin, height() - 2 * Margin);
    if (!rect.isValid())
        return;

    CGPlotSettings settings = zoomStack[curZoom];
    QPen quiteDark = palette().dark().color().light();
    QPen light = palette().light().color();

    for (int i = 0; i <= settings.numXTicks; ++i)
    {
        int x = rect.left() + (i * (rect.width() - 1)
                                    / settings.numXTicks);
        double label = settings.minX + (i * settings.spanX()
                                        / settings.numXTicks);
        painter->setPen(quiteDark);
        painter->drawLine(x, rect.top(), x, rect.bottom());
        painter->setPen(light);
        painter->drawLine(x, rect.bottom(), x, rect.bottom() + 5);
        painter->drawText(x - 50, rect.bottom() + 5, 100, 15,
                            Qt::AlignHCenter | Qt::AlignTop,
                            QString::number(label));
    }

    for (int j = 0; j <= settings.numYTicks; ++j)
    {
        int y = rect.bottom() - (j * (rect.height() - 1)
                                    / settings.numYTicks);
        double label = settings.minY + (j * settings.spanY()
                                        / settings.numYTicks);
        painter->setPen(quiteDark);
        painter->drawLine(rect.left(), y, rect.right(), y);
        painter->setPen(light);
        painter->drawLine(rect.left() - 5, y, rect.left(), y);
        painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20,
                            Qt::AlignRight | Qt::AlignVCenter,
                            QString::number(label));
    }

    painter->drawRect(rect.adjusted(0, 0, -1, -1));
}

/*
 * The drawCurves() function draws the curves on top of the grid. We start by
 * calling setClipRect() to set the QPainter ’s clip region to the rectangle that
 * contains the curves (excluding the margins and the frame around the graph).
 * QPainter will then ignore drawing operations on pixels outside the area.
 * Next, we iterate over all the curves using a Java-style iterator, and for each
 * curve, we iterate over its constituent QPointF s. The key() function gives the
 * curve’s ID, and the value() function gives the corresponding curve data as a
 * QVector<QPointF> . The inner for loop converts each QPointF from plotter coordinates
 * to widget coordinates and stores them in the polyline variable.
 * Once we have converted all the points of a curve to widget coordinates, we
 * set the pen color for the curve (using one of a set of predefined colors) and call
 * drawPolyline() to draw a line that goes through all the curve’s points.
*/
void CGPlotter::drawCurves(QPainter *painter)
{
    static const QColor colorForIds[6] = {
        Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta, Qt::yellow
    };
    CGPlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);
    if (!rect.isValid())
        return;

    painter->setClipRect(rect.adjusted(+1, +1, -1, -1));

    QMapIterator<int, QVector<QPointF> > i(curveMap);
    while (i.hasNext())
    {
        i.next();
        int id = i.key();
        const QVector<QPointF> &data = i.value();
        QPolygonF polyline(data.count());

        for (int j = 0; j < data.count(); ++j)
        {
            double dx = data[j].x() - settings.minX;
            double dy = data[j].y() - settings.minY;
            double x = rect.left() + (dx * (rect.width() - 1) / settings.spanX());
            double y = rect.bottom() - (dy * (rect.height() - 1) / settings.spanY());

            polyline[j] = QPointF(x, y);
        }

        painter->setPen(colorForIds[uint(id) % 6]);
        painter->drawPolyline(polyline);
    }
}
