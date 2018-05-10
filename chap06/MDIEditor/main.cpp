/*
 * Applications that provide multiple documents within the main window’s central
 * area are called multiple document interface applications, or MDI applications.
 * In Qt, an MDI application is created by using the QWorkspace class
 * as the central widget and by making each document window a child of the
 * QWorkspace.
 * It is conventional for MDI applications to provide a Window menu that includes
 * some commands for managing the windows and the list of windows. The active
 * window is identified with a checkmark. The user can make any window active
 * by clicking its entry in the Window menu.
*/

#include <QApplication>

#include "cgmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CGMainWindow mainWin;
    mainWin.show();
    return app.exec();
}
