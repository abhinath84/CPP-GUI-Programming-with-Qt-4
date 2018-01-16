#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent=0);
    ~GoToCellDialog();

private slots:
    void on_lineEdit_textChanged();

private:
    QLabel      *lblCellLoc;
    QLineEdit   *txtLoc;
    QPushButton *btnOk;
    QPushButton *btnCancel;
};

#endif // GOTOCELLDIALOG_H
