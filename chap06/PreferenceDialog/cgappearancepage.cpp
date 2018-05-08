#include "cgappearancepage.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>


CGAppearancePage::CGAppearancePage(QWidget *parent)
    : QWidget(parent)
{
    openGroupBox = new QGroupBox(tr("Open at startup"));
    webBrowserCheckBox = new QCheckBox(tr("Web browser"));
    mailEditorCheckBox = new QCheckBox(tr("Mail editor"));
    newsgroupCheckBox = new QCheckBox(tr("Newsgroups"));

    toolbarsGroupBox = new QGroupBox(tr("Show toolbars as"));
    picturesAndTextRadioButton = new QRadioButton(tr("Pictures and "
                                                     "text"));
    picturesOnlyRadioButton = new QRadioButton(tr("Pictures only"));
    textOnlyRadioButton = new QRadioButton(tr("Text only"));

    tooltipsCheckBox = new QCheckBox(tr("Show tooltips"));
    webSiteIconsCheckBox = new QCheckBox(tr("Show web site icons"));
    resizeImagesCheckBox = new QCheckBox(tr("Resize large images to "
                                            "fit in the window"));

    QVBoxLayout *openLayout = new QVBoxLayout;
    openLayout->addWidget(webBrowserCheckBox);
    openLayout->addWidget(mailEditorCheckBox);
    openLayout->addWidget(newsgroupCheckBox);
    openGroupBox->setLayout(openLayout);

    QVBoxLayout *toolbarsLayout = new QVBoxLayout;
    toolbarsLayout->addWidget(picturesAndTextRadioButton);
    toolbarsLayout->addWidget(picturesOnlyRadioButton);
    toolbarsLayout->addWidget(textOnlyRadioButton);
    toolbarsGroupBox->setLayout(toolbarsLayout);

    QVBoxLayout *pageLayout = new QVBoxLayout;
    pageLayout->setMargin(0);
    pageLayout->addWidget(openGroupBox);
    pageLayout->addWidget(toolbarsGroupBox);
    pageLayout->addWidget(tooltipsCheckBox);
    pageLayout->addWidget(webSiteIconsCheckBox);
    pageLayout->addWidget(resizeImagesCheckBox);
    pageLayout->addStretch();
    this->setLayout(pageLayout);

    webBrowserCheckBox->setChecked(true);
    mailEditorCheckBox->setChecked(true);
    picturesAndTextRadioButton->setChecked(true);
    tooltipsCheckBox->setChecked(true);
    webSiteIconsCheckBox->setChecked(true);
}
