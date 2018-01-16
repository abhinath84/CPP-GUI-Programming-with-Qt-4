#include <QtGui>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>

#include "CGFindDialog.h"
#include "CGGoToCellDialog.h"
#include "CGSortDialog.h"
#include "CGSpreadsheet.h"
#include "CGMainWindow.h"

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

    findDialog = 0;

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");
}

void CGMainWindow::createActions()
{
    actNew = new QAction(tr("&New"), this);
    actNew->setIcon(QIcon(":/images/new.png"));
    actNew->setShortcut(QKeySequence::New);
    actNew->setStatusTip(tr("Create a new spreadsheet file"));
    connect(actNew, SIGNAL(triggered()), this, SLOT(newFile()));

    actOpen = new QAction(tr("&Open..."), this);
    actOpen->setIcon(QIcon(":/images/open.png"));
    actOpen->setShortcut(QKeySequence::Open);
    actOpen->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(actOpen, SIGNAL(triggered()), this, SLOT(open()));

    actSave = new QAction(tr("&Save"), this);
    actSave->setIcon(QIcon(":/images/save.png"));
    actSave->setShortcut(QKeySequence::Save);
    actSave->setStatusTip(tr("Save the spreadsheet to disk"));
    connect(actSave, SIGNAL(triggered()), this, SLOT(save()));

    actSaveAs = new QAction(tr("Save &As..."), this);
    actSaveAs->setStatusTip(tr("Save the spreadsheet under a new "
                                  "name"));
    connect(actSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

    for (int i = 0; i < MaxRecentFiles; ++i)
    {
        actRecentFiles[i] = new QAction(this);
        actRecentFiles[i]->setVisible(false);
        connect(actRecentFiles[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

    actExit = new QAction(tr("E&xit"), this);
    actExit->setShortcut(tr("Ctrl+Q"));
    actExit->setStatusTip(tr("Exit the application"));
    connect(actExit, SIGNAL(triggered()), this, SLOT(close()));

    actCut = new QAction(tr("Cu&t"), this);
    actCut->setIcon(QIcon(":/images/cut.png"));
    actCut->setShortcut(QKeySequence::Cut);
    actCut->setStatusTip(tr("Cut the current selection's contents "
                               "to the clipboard"));
    connect(actCut, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

    actCopy = new QAction(tr("&Copy"), this);
    actCopy->setIcon(QIcon(":/images/copy.png"));
    actCopy->setShortcut(QKeySequence::Copy);
    actCopy->setStatusTip(tr("Copy the current selection's contents "
                                "to the clipboard"));
    connect(actCopy, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

    actPaste = new QAction(tr("&Paste"), this);
    actPaste->setIcon(QIcon(":/images/paste.png"));
    actPaste->setShortcut(QKeySequence::Paste);
    actPaste->setStatusTip(tr("Paste the clipboard's contents into "
                                 "the current selection"));
    connect(actPaste, SIGNAL(triggered()),
            spreadsheet, SLOT(paste()));

    actDelete = new QAction(tr("&Delete"), this);
    actDelete->setShortcut(QKeySequence::Delete);
    actDelete->setStatusTip(tr("Delete the current selection's "
                                  "contents"));
    connect(actDelete, SIGNAL(triggered()),
            spreadsheet, SLOT(del()));

    actSelectRow = new QAction(tr("&Row"), this);
    actSelectRow->setStatusTip(tr("Select all the cells in the "
                                     "current row"));
    connect(actSelectRow, SIGNAL(triggered()),
            spreadsheet, SLOT(selectCurrentRow()));

    actSelectColumn = new QAction(tr("&Column"), this);
    actSelectColumn->setStatusTip(tr("Select all the cells in the "
                                        "current column"));
    connect(actSelectColumn, SIGNAL(triggered()),
            spreadsheet, SLOT(selectCurrentColumn()));

    actSelectAll = new QAction(tr("&All"), this);
    actSelectAll->setShortcut(QKeySequence::SelectAll);
    actSelectAll->setStatusTip(tr("Select all the cells in the "
                                     "spreadsheet"));
    connect(actSelectAll, SIGNAL(triggered()),
            spreadsheet, SLOT(selectAll()));

    actFind = new QAction(tr("&Find..."), this);
    actFind->setIcon(QIcon(":/images/find.png"));
    actFind->setShortcut(QKeySequence::Find);
    actFind->setStatusTip(tr("Find a matching cell"));
    connect(actFind, SIGNAL(triggered()), this, SLOT(find()));

    actGoToCell = new QAction(tr("&Go to Cell..."), this);
    actGoToCell->setIcon(QIcon(":/images/gotocell.png"));
    actGoToCell->setShortcut(tr("Ctrl+G"));
    actGoToCell->setStatusTip(tr("Go to the specified cell"));
    connect(actGoToCell, SIGNAL(triggered()),
            this, SLOT(goToCell()));

    actRecalculate = new QAction(tr("&Recalculate"), this);
    actRecalculate->setShortcut(tr("F9"));
    actRecalculate->setStatusTip(tr("Recalculate all the "
                                       "spreadsheet's formulas"));
    connect(actRecalculate, SIGNAL(triggered()),
            spreadsheet, SLOT(recalculate()));

    actSort = new QAction(tr("&Sort..."), this);
    actSort->setStatusTip(tr("Sort the selected cells or all the "
                                "cells"));
    connect(actSort, SIGNAL(triggered()), this, SLOT(sort()));

    actShowGrid = new QAction(tr("&Show Grid"), this);
    actShowGrid->setCheckable(true);
    actShowGrid->setChecked(spreadsheet->showGrid());
    actShowGrid->setStatusTip(tr("Show or hide the spreadsheet's "
                                    "grid"));
    connect(actShowGrid, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(setShowGrid(bool)));
#if QT_VERSION < 0x040102
    // workaround for a QTableWidget bug in Qt 4.1.1
    connect(actShowGrid, SIGNAL(toggled(bool)),
            spreadsheet->viewport(), SLOT(update()));
#endif

    actAutoRecalc = new QAction(tr("&Auto-Recalculate"), this);
    actAutoRecalc->setCheckable(true);
    actAutoRecalc->setChecked(spreadsheet->autoRecalculate());
    actAutoRecalc->setStatusTip(tr("Switch auto-recalculation on or "
                                      "off"));
    connect(actAutoRecalc, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(setAutoRecalculate(bool)));

    actAbout = new QAction(tr("&About"), this);
    actAbout->setStatusTip(tr("Show the application's About box"));
    connect(actAbout, SIGNAL(triggered()), this, SLOT(about()));

    actAboutQt = new QAction(tr("About &Qt"), this);
    actAboutQt->setStatusTip(tr("Show the Qt library's About box"));
    connect(actAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void CGMainWindow::createMenus()
{
    mnuFile = menuBar()->addMenu(tr("&File"));

    mnuFile->addAction(actNew);
    mnuFile->addAction(actOpen);
    mnuFile->addAction(actSave);
    mnuFile->addAction(actSaveAs);
    actSeparator = mnuFile->addSeparator();
    for(int i = 0; i < MaxRecentFiles; i++)
        mnuFile->addAction(actRecentFiles[i]);
    mnuFile->addSeparator();
    mnuFile->addAction(actExit);

    mnuEdit = menuBar()->addMenu(tr("&Edit"));
    mnuEdit->addAction(actCut);
    mnuEdit->addAction(actCopy);
    mnuEdit->addAction(actPaste);
    mnuEdit->addAction(actDelete);
    mnuSelectSub = mnuEdit->addMenu(tr("&Select"));
    mnuSelectSub->addAction(actSelectRow);
    mnuSelectSub->addAction(actSelectColumn);
    mnuSelectSub->addAction(actSelectAll);
    mnuEdit->addSeparator();
    mnuEdit->addAction(actFind);
    mnuEdit->addAction(actGoToCell);

    mnuTools = menuBar()->addMenu(tr("&Tools"));
    mnuTools->addAction(actRecalculate);
    mnuTools->addAction(actSort);

    mnuOptions = menuBar()->addMenu(tr("&Options"));
    mnuOptions->addAction(actShowGrid);
    mnuOptions->addAction(actAutoRecalc);

    menuBar()->addSeparator();

    mnuHelp = menuBar()->addMenu(tr("&Help"));
    mnuHelp->addAction(actAbout);
    mnuHelp->addAction(actAboutQt);
}

void CGMainWindow::createContextMenu()
{
    spreadsheet->addAction(actCut);
    spreadsheet->addAction(actCopy);
    spreadsheet->addAction(actPaste);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void CGMainWindow::createToolBars()
{
    tlbFile = addToolBar(tr("&File"));
    tlbFile->addAction(actNew);
    tlbFile->addAction(actOpen);
    tlbFile->addAction(actSave);

    tlbEdit = addToolBar(tr("&Edit"));
    tlbEdit->addAction(actCut);
    tlbEdit->addAction(actCopy);
    tlbEdit->addAction(actPaste);
    tlbEdit->addSeparator();
    tlbEdit->addAction(actFind);
    tlbEdit->addAction(actGoToCell);
}
