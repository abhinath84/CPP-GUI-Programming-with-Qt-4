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
    /*actNew = new QAction(tr("&New"), this);
    actNew->setIcon(QIcon(":/images/new.png"));
    actNew->setShortcut(tr("Ctrl+N"));
    actNew->setStatusTip(tr("Create a new spreadsheet file"));
    connect(actNew, &QAction::triggered,
            this, &CGMainWindow::newFile);*/

//    CGMenuActionData data(this, "&New", ":/images/new.png", "Ctrl+N",
//                          "Create a new spreadsheet file", this,
//                          SIGNAL(triggered(bool), SLOT(newFile()));
    createMenuAction(actNew, CGMenuActionData((this, "&New", ":/images/new.png", "Ctrl+N",
                                               "Create a new spreadsheet file", this,
                                               SIGNAL(triggered(bool)), SLOT(newFile()))));
}

void CGMainWindow::createMenuAction(QAction *action, const CGMenuActionData &data)
{
    if(( action != NULL ) && ( data.isProper() ))
    {
        action = new QAction(tr(data.Text()), data.Parent());
        action->setIcon(QIcon(data.Icon()));
        action->setShortcut(tr(data.Shortcut()));
        action->setStatusTip(tr(data.StatusTip()));
        connect(action, data.Signal().toStdString().c_str(),
                data.Receiver, data.Slot().toStdString().c_str());
    }
}
