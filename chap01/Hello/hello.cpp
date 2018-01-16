/*
 * greaterThan(QT_MAJOR_VERSION, 4): QT +=widgets
 *
 * Below classes belongs to widget framework/package.
 * Need to add above line in .pro file to access widget related classes.
 *
 * This app shows how to create a widget based QT application.
 * Basic idea of qmake file (.pro file) and build the app.
*/

#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QLabel *label = new QLabel("<h2><i>Hello</i> <font color=red>Qt!</font></h2>");
    label->windowTitleChanged("Hello");
    label->resize(100, 50);
    label->show();

    return app.exec();
}
