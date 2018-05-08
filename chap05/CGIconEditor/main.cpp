#include <QApplication>
#include <QScrollArea>

#include "CGIconEditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*CGIconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor.resize(250, 250);

    QImage img(":/images/mouse.png");

    iconEditor.setIconImage(img);
    iconEditor.show();*/

    CGIconEditor *iconEditor = new CGIconEditor;
    iconEditor->setIconImage(QImage(":/images/mouse.png"));

    QScrollArea scrollArea;
    scrollArea.setWidget(iconEditor);
    scrollArea.viewport()->setBackgroundRole(QPalette::Dark);
    scrollArea.viewport()->setAutoFillBackground(true);
    scrollArea.setWindowTitle(QObject::tr("Icon Editor"));
    scrollArea.show();

    return app.exec();
}
