#ifndef CGFINDDIALOG_H
#define CGFINDDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QCheckBox;
class QDialogButtonBox;
class QPushButton;

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
};

#endif // CGFINDDIALOG_H
