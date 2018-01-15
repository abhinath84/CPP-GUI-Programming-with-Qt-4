#include <QApplication>

#include "cgfinddialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CGFindDialog *find = new CGFindDialog();
    find->show();

    return app.exec();
}
