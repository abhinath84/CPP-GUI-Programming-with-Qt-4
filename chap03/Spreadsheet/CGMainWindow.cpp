#include <QtWidgets>
#include <CGFindDialog>
#include <CGGoToCellDialog>
#include <CGSortDialog>
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
    createAction( actNew, CGMenuActionData(this, "&New", ":/images/new.png",
                            QKeySequence::New,"Create a new spreadsheet file",
                            this, SIGNAL(triggered()), SLOT(newFile())) );

    createAction( openAction, CGMenuActionData(this, "&Open...", ":/images/open.png",
                            QKeySequence::Open,"Open an existing spreadsheet file",
                            this, SIGNAL(triggered()), SLOT(open())) );

    createAction( saveAction, CGMenuActionData(this, "&Save", ":/images/save.png",
                            QKeySequence::Save,"Save the spreadsheet to disk",
                            this, SIGNAL(triggered()), SLOT(save())) );

    createAction( saveAsAction, CGMenuActionData(this, "Save &As...", "",
                            QKeySequence::SaveAs,"Save the spreadsheet under a new name",
                            this, SIGNAL(triggered()), SLOT(saveAs())) );

    for (int i = 0; i < MaxRecentFiles; ++i)
    {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }
}

bool CGMainWindow::createAction(QAction **action, const CGMenuActionData &data)
{
    bool status = false;

    if(action != NULL)
        status = data.setAction(action);

    return(status);
}
