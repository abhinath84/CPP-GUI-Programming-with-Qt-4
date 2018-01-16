#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
    class SortDialog;
}   // namespace Ui

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent=0);
    ~SortDialog();

    void setColumnRange(QChar first, QChar last);

private:
    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H
