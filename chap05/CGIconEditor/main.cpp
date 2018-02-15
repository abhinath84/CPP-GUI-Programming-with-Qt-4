#include <QApplication>

#include "CGIconEditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CGIconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor.setIconImage(QImage(":/images/mouse.png"));
    iconEditor.show();

    return app.exec();
}
