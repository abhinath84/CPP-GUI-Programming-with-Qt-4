#include <QApplication>
#include <QHBoxLayout>

#include "CGHexSpinBox.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CGHexSpinBox spinBox;
    spinBox.setWindowTitle(QObject::tr("Hex Spin Box"));
    spinBox.show();

    return app.exec();
}
