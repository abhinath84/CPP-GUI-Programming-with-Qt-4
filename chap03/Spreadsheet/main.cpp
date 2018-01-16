#include <QApplication>

#include"CGMainWindow.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CGMainWindow *spreadsheet = new CGMainWindow();
    spreadsheet->show();

    return(app.exec());
}
