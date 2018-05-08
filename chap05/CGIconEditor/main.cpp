#include <QApplication>

#include "CGIconEditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CGIconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor.resize(250, 250);

    QImage img(":/images/mouse.png");

    iconEditor.setIconImage(img);
    iconEditor.show();

    return app.exec();
}
