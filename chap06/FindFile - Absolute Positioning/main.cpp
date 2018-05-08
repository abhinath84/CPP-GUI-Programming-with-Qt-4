#include <QtWidgets>

#include "cgfindfiledialog.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CGFindFileDialog dialog;
    dialog.show();

    return(app.exec());
}
