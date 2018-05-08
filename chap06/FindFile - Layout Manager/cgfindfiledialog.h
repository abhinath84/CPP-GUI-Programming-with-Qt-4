/*
 * The most convenient solution for laying out widgets on a form is to use Qt’s
 * layout managers. The layout managers provide sensible defaults for every
 * type of widget and take into account each widget’s size hint, which in turn
 * typically depends on the widget’s font, style, and contents. Layout managers
 * also respect minimum and maximum sizes, and automatically adjust the
 * layout in response to font changes, content changes, and window resizing.
 *
 * The three most important layout managers are QHBoxLayout , QVBoxLayout , and
 * QGridLayout . These classes inherit QLayout , which provides the basic framework
 * for layouts. All three classes are fully supported by Qt Designer and can also
 * be used directly in code.
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
