#ifndef CGAPPEARANCEPAGE_H
#define CGAPPEARANCEPAGE_H

#include <QWidget>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout;

class CGAppearancePage : public QWidget
{
    Q_OBJECT
public:
    explicit CGAppearancePage(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGroupBox *openGroupBox;
    QCheckBox *webBrowserCheckBox;
    QCheckBox *mailEditorCheckBox;
    QCheckBox *newsgroupCheckBox;
    QGroupBox *toolbarsGroupBox;
    QRadioButton *picturesAndTextRadioButton;
    QRadioButton *picturesOnlyRadioButton;
    QRadioButton *textOnlyRadioButton;
    QCheckBox *tooltipsCheckBox;
    QCheckBox *webSiteIconsCheckBox;
    QCheckBox *resizeImagesCheckBox;
};

#endif // CGAPPEARANCEPAGE_H
