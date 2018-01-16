#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

// Forward declaration of necessary widgets to avoid include
// corresponding header file which will help compiler to execute
// faster.
//
// We are able to do that as we are using pointer of those classes
// to define instances instead using object.

class QCheckBox;
class QLabel;
class QLineEdit;
class QDialogButtonBox;
class QPushButton;


class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);

// Never defined signal's function. They are automatically
// defined in meta-data section by QT compiler.
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

// slot is like event of any widget.
// OR, member function of any class.
private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel              *lblFindWhat;
    QLineEdit           *txtFind;
    QCheckBox           *chkboxCase;
    QCheckBox           *chkboxFromStart;
    QCheckBox           *chkboxBackward;
    QCheckBox           *chkboxWholeWords;
    QCheckBox           *chkboxSearchSelection;
    QDialogButtonBox    *btnBox;
    QPushButton         *btnFind;
    QPushButton         *btnClose;
    QPushButton         *btnMore;
    QWidget             *extension;
};

#endif // FINDDIALOG_H
