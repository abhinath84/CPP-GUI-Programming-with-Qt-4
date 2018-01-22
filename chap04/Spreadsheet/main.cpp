#include <QApplication>
#include <QSplashScreen>

#include"CGMainWindow.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    /// Splashscreen.
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting up the main window..."),
                        topRight, Qt::white);

    CGMainWindow mainwindow;

    splash->showMessage(QObject::tr("Loading modules..."),
                        topRight, Qt::white);

    loadModules();

    splash->showMessage(QObject::tr("Establishing connections..."),
                        topRight, Qt::white);

    establishConnections();


    mainwindow.show();
    splash->finish(&mainwindow);
    delete splash;

    return(app.exec());
}
