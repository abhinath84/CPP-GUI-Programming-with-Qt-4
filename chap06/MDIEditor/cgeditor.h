#ifndef EDITOR_H
#define EDITOR_H

#include <QTextEdit>

class CGEditor : public QTextEdit
{
    Q_OBJECT

public:
    CGEditor(QWidget *parent = 0);

    void newFile();
    bool save();
    bool saveAs();
    QSize sizeHint() const;
    QAction *windowMenuAction() const { return action; }

    static CGEditor *open(QWidget *parent = 0);
    static CGEditor *openFile(const QString &fileName,
                            QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();

private:
    bool okToContinue();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    void tabSetting();

    QString curFile;
    bool isUntitled;
    QAction *action;
};

#endif
