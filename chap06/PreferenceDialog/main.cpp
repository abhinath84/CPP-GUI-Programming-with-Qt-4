#include <QApplication>

#include "cgpreferencedialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CGPreferenceDialog dialog;
    dialog.show();
    return app.exec();
}
