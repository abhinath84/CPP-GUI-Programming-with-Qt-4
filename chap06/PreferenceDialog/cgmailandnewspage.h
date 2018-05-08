#ifndef CGMAILANDNEWSPAGE_H
#define CGMAILANDNEWSPAGE_H

#include <QWidget>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;

class CGMailAndNewsPage : public QWidget
{
    Q_OBJECT
public:
    explicit CGMailAndNewsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGroupBox *generalGroupBox;
    QCheckBox *confirmCheckBox;
    QCheckBox *rememberCheckBox;
    QGroupBox *mailButtonsGroupBox;
    QCheckBox *fileCheckBox;
    QCheckBox *nextCheckBox;
    QCheckBox *stopCheckBox;
    QCheckBox *junkCheckBox;
};

#endif // CGMAILANDNEWSPAGE_H
