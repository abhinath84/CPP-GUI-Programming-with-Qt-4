#include <QApplication>
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

//    FindDialog *findDialog = new FindDialog();
//    findDialog->show();

//    GoToCellDialog *gtcDialog = new GoToCellDialog();
//    gtcDialog->show();

    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('C', 'F');
    dialog->show();

    return app.exec();
}
