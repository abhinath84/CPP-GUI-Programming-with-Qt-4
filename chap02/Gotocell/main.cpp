#include <QApplication>
#include "gotocelldialog.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  GoToCellDialog *dialog = new GoToCellDialog();
  //dialog->setFixedSize(dialog->sizeHint().width(), dialog->sizeHint().height());
  dialog->show();

  return app.exec();
}
