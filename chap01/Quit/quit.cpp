/*
 * This project demonstrate the use of widgets in QT
 * and how to use SIGNAL & SLOT.
*/

#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton btn("Quit");
    btn.setWindowTitle("PushButton Example");
    btn.resize(300, 50);
    QObject::connect(&btn, SIGNAL(clicked(bool)),
                     &app, SLOT(quit()));
    btn.show();

    return app.exec();
}
