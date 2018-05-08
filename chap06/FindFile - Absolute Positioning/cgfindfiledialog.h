/*
 * Absolute positioning is the crudest way of laying out widgets. It is achieved by
 * assigning hard-coded sizes and positions to the form’s child widgets and a fixed
 * size to the form.
 *
 * Absolute positioning has many disadvantages:
 * • The user cannot resize the window.
 * • Some text may be truncated if the user chooses an unusually large font or
 *   if the application is translated into another language.
 * • The widgets might have inappropriate sizes for some styles.
 * • The positions and sizes must be calculated manually. This is tedious and
 *   error-prone, and makes maintenance painful.
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
