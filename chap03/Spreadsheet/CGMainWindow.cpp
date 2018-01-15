#include <QtWidgets>
#include <CGFindDialog>
//#include <CGGoToCell>
//#include <CGSortDialog>
//#include <CGSpreadsheet>
#include <CGMenuActionData>

#include "CGMainWindow"

CGMainWindow::CGMainWindow()
{
    spreadsheet = new CGSpreadsheet();
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    find = 0;

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");
}

void CGMainWindow::createActions()
{
    actNew = new QAction(tr("&New"), this);
    actNew->setIcon(QIcon(":/images/new.png"));
    actNew->setShortcut(tr("Ctrl+N"));
    actNew->setStatusTip(tr("Create a new spreadsheet file"));
    connect(actNew, &QAction::triggered,
            this, &CGMainWindow::newFile);
}
