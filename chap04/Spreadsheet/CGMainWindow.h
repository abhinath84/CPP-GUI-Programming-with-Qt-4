#ifndef CGMAINWINDOW_H
#define CGMAINWINDOW_H

#include <QMainWindow>


class QAction;
class QLabel;
class CGFindDialog;
class CGSortDialog;
class CGGoToCell;
class CGSpreadsheet;


class CGMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CGMainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

private:
    CGSpreadsheet   *spreadsheet;
    CGFindDialog    *findDialog;
    QLabel          *lblLocation;
    QLabel          *lblFormula;
    QStringList     strListRecentFiles;
    QString         strCurFile;

    enum { MaxRecentFiles = 5 };
    QAction         *actRecentFiles[MaxRecentFiles];
    QAction         *actSeparator;

    QMenu           *mnuFile;
    QMenu           *mnuEdit;
    QMenu           *mnuSelectSub;
    QMenu           *mnuTools;
    QMenu           *mnuOptions;
    QMenu           *mnuHelp;
    QToolBar        *tlbFile;
    QToolBar        *tlbEdit;
    QAction         *actNew;
    QAction         *actOpen;
    QAction         *actSave;
    QAction         *actSaveAs;
    QAction         *actExit;
    QAction         *actCut;
    QAction         *actCopy;
    QAction         *actPaste;
    QAction         *actDelete;
    QAction         *actSelectRow;
    QAction         *actSelectColumn;
    QAction         *actSelectAll;
    QAction         *actFind;
    QAction         *actGoToCell;
    QAction         *actRecalculate;
    QAction         *actSort;
    QAction         *actShowGrid;
    QAction         *actAutoRecalc;
    QAction         *actAbout;
    QAction         *actAboutQt;
};

#endif // CGMAINWINDOW
