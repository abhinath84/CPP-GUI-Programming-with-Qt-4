#ifndef CGWEBBROWSERPAGE_H
#define CGWEBBROWSERPAGE_H

#include <QWidget>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;

class CGWebBrowserPage : public QWidget
{
    Q_OBJECT
public:
    explicit CGWebBrowserPage(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGroupBox *displayGroupBox;
    QRadioButton *blankRadioButton;
    QRadioButton *homeRadioButton;
    QRadioButton *lastRadioButton;
    QGroupBox *homeGroupBox;
    QLabel *locationLabel;
    QLineEdit *locationLineEdit;
    QGroupBox *webButtonsGroupBox;
    QCheckBox *bookmarksCheckBox;
    QCheckBox *goCheckBox;
    QCheckBox *homeCheckBox;
    QCheckBox *searchCheckBox;
    QCheckBox *printCheckBox;
};

#endif // CGWEBBROWSERPAGE_H
