#ifndef CGGOTOCELLDIALOG_H
#define CGGOTOCELLDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class CGGoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    CGGoToCellDialog(QWidget *parent=0);
    ~CGGoToCellDialog();

private slots:
    void on_lineEdit_textChanged();

private:
    QLabel      *lblCellLoc;
    QLineEdit   *txtLoc;
    QPushButton *btnOk;
    QPushButton *btnCancel;
};

#endif // CGGOTOCELLDIALOG_H
