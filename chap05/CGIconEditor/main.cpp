#include <QApplication>

#include "CGIconEditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CGIconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor.resize(250, 250);

    // "/run/media/anath/data/anath/myproj/QT/C++ GUI Programming with Qt 4/chap05/build-IconEditor-Desktop_Qt_5_10_0_GCC_64bit-Debug/images/mouse.png"
    QImage img(":/images/mouse.png");

    iconEditor.setIconImage(img);
    iconEditor.show();

    return app.exec();
}
