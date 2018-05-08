/*
 * An alternative to absolute positioning is manual layout. With manual layout,
 * the widgets are still given absolute positions, but their sizes are made proportional
 * to the size of the window rather than being entirely hard-coded. This
 * can be achieved by reimplementing the form’s resizeEvent() function to set its
 * child widgets’ geometries.
 * Just like absolute positioning, manual layout requires a lot of hard-coded constants
 * to be calculated by the programmer. Writing code like this is tiresome,
 * especially if the design changes. And there is still the risk of text truncation.
 * We can avoid this risk by taking account of the child widgets’ size hints, but
 * that would complicate the code even further.
*/

#ifndef CGFINDFILEDIALOG_H
#define CGFINDFILEDIALOG_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;


class CGFindFileDialog : public QDialog
{
public:
    CGFindFileDialog(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QLabel *namedLabel;
    QLabel *lookInLabel;
    QLineEdit *lookInLineEdit;
    QLineEdit *namedLineEdit;
    QCheckBox *subfoldersCheckBox;
    QTableWidget *tableWidget;
    QLabel *messageLabel;
    QPushButton *findButton;
    QPushButton *stopButton;
    QPushButton *closeButton;
    QPushButton *helpButton;
};

#endif // CGFINDFILEDIALOG_H
