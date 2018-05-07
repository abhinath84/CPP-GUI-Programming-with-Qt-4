#ifndef CGPLOTTER_H
#define CGPLOTTER_H

#include<QMap>
#include<QPixmap>
#include<QVector>
#include<QWidget>

#include "CGPlotSettings.h"


// Class forward declaration
class QToolButton;


class CGPlotter : public QWidget
{
    Q_OBJECT
public:
    CGPlotter(QWidget *parent = 0);

    /*
     * In the Plotter class, we provide three public functions for setting up the plot,
     * and two public slots for zooming in and out. We also reimplement minimum-
     * SizeHint() and sizeHint() from QWidget . We store a curve’s points as a QVec-
     * tor<QPointF> , where QPointF is a floating-point version of QPoint .
    */
    void setPlotSettings(const CGPlotSettings &settings);
    void setCurveData(int id, const QVector<QPointF> &data);
    void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);

private:
    enum { Margin = 50 };

    QToolButton *tlbtnZoomIn;
    QToolButton *tlbtnZoomOut;
    QMap<int, QVector<QPointF> > curveMap;

    /*
     * The zoom stack is represented by two member variables:
     *  • zoomStack holds the different zoom settings as a QVector<PlotSettings> .
     *  • curZoom holds the current PlotSettings ’s index in the zoomStack .
    */
    QVector<CGPlotSettings> zoomStack;
    int curZoom;

    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;

};

#endif // CGPLOTTER_H
