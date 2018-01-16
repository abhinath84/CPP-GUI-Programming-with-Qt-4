#ifndef CGFINDDIALOG_H
#define CGFINDDIALOG_H

#include <QDialog>
#include <CGMenuActionData>

class QLabel;
class QLineEdit;
class QCheckBox;
class QDialogButtonBox;
class QPushButton;
class QAction;

class CGFindDialog : public QDialog
{
    Q_OBJECT

public:
    CGFindDialog(QWidget *parent = 0);
    ~CGFindDialog();

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    void func(QAction **act);
    void createAction(QAction **act, const CGMenuActionData &data);

private:
    QWidget             *extension;
    QLabel              *lblFindWhat;
    QLineEdit           *txtFindWhat;
    QCheckBox           *chkMatchCase;
    QCheckBox           *chkSearchFromStart;
    QCheckBox           *chkSearchBackward;
    QCheckBox           *chkWholeWords;
    QCheckBox           *chkSearchSelection;
    QDialogButtonBox    *btnBox;
    QPushButton         *btnFind;
    QPushButton         *btnCancel;
    QPushButton         *btnMore;

    QAction             *act;
};

#endif // CGFINDDIALOG_H
