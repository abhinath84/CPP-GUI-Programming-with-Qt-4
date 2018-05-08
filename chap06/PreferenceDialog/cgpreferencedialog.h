/*
 * The QStackedLayout class lays out a set of child widgets, or “pages”, and shows
 * only one at a time, hiding the others from the user. The QStackedLayout itself
 * is invisible and provides no intrinsic means for the user to change page. The
 * small arrows and the dark gray frame in Figure 6.5 are provided by Qt Designer
 * to make the layout easier to design with. For convenience, Qt also includes
 * QStackedWidget, which provides a QWidget with a built-in QStackedLayout.
 * The pages are numbered from 0.To make a specific child widget visible, we can
 * call setCurrentIndex() with a page number. The page number for a child widget
 * is available using indexOf().
*/

#ifndef CGPREFERENCEDIALOG_H
#define CGPREFERENCEDIALOG_H

#include <QDialog>


class QListWidget;
class QStackedLayout;
class QDialogButtonBox;

class CGAdvancedPage;
class CGAppearancePage;
class CGWebBrowserPage;
class CGMailAndNewsPage;


class CGPreferenceDialog : public QDialog
{
    Q_OBJECT

public:
    CGPreferenceDialog(QWidget *parent = 0);

private:
    CGAppearancePage *appearancePage;
    CGWebBrowserPage *webBrowserPage;
    CGMailAndNewsPage *mailAndNewsPage;
    CGAdvancedPage *advancedPage;

    QStackedLayout *stackedLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
};

#endif  // CGPREFERENCEDIALOG_H
