#include "cgmailandnewspage.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>


CGMailAndNewsPage::CGMailAndNewsPage(QWidget *parent)
    : QWidget(parent)
{
    generalGroupBox = new QGroupBox(tr("General settings"));
    confirmCheckBox = new QCheckBox(tr("Warn when moving folders to "
                                       "the Trash"));
    rememberCheckBox = new QCheckBox(tr("Remember the last selected "
                                        "message"));

    mailButtonsGroupBox = new QGroupBox(tr("Select the buttons you "
                                           "want in the toolbar"));
    fileCheckBox = new QCheckBox(tr("File"));
    nextCheckBox = new QCheckBox(tr("Next"));
    stopCheckBox = new QCheckBox(tr("Stop"));
    junkCheckBox = new QCheckBox(tr("Junk"));

    QVBoxLayout *generalLayout = new QVBoxLayout;
    generalLayout->addWidget(confirmCheckBox);
    generalLayout->addWidget(rememberCheckBox);
    generalGroupBox->setLayout(generalLayout);

    QGridLayout *mailButtonsLayout = new QGridLayout;
    mailButtonsLayout->addWidget(fileCheckBox, 0, 0);
    mailButtonsLayout->addWidget(nextCheckBox, 1, 0);
    mailButtonsLayout->addWidget(stopCheckBox, 0, 1);
    mailButtonsLayout->addWidget(junkCheckBox, 1, 1);
    mailButtonsGroupBox->setLayout(mailButtonsLayout);

    QVBoxLayout *pageLayout = new QVBoxLayout;
    pageLayout->setMargin(0);
    pageLayout->addWidget(generalGroupBox);
    pageLayout->addWidget(mailButtonsGroupBox);
    pageLayout->addStretch();
    this->setLayout(pageLayout);

    confirmCheckBox->setChecked(true);
    rememberCheckBox->setChecked(true);
    nextCheckBox->setChecked(true);
    junkCheckBox->setChecked(true);
}
