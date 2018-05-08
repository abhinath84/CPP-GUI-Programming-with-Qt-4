#include "cgadvancedpage.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>


CGAdvancedPage::CGAdvancedPage(QWidget *parent)
    : QWidget(parent)
{
    featuresGroupBox = new QGroupBox(tr("Features that help "
                                        "interpret web pages"));
    javaCheckBox = new QCheckBox(tr("Enable Java"));
    ftpCheckBox = new QCheckBox(tr("Use this email address for "
                                   "anonymous FTP:"));
    ftpLineEdit = new QLineEdit;

    connect(ftpCheckBox, SIGNAL(toggled(bool)),
            ftpLineEdit, SLOT(setEnabled(bool)));

    QGridLayout *featuresLayout = new QGridLayout;
    featuresLayout->addWidget(javaCheckBox, 0, 0, 1, 2);
    featuresLayout->addWidget(ftpCheckBox, 1, 0, 1, 2);
    featuresLayout->addWidget(ftpLineEdit, 2, 1);
    featuresGroupBox->setLayout(featuresLayout);

    QVBoxLayout *pageLayout = new QVBoxLayout;
    pageLayout->setMargin(0);
    pageLayout->addWidget(featuresGroupBox);
    pageLayout->addStretch();
    this->setLayout(pageLayout);

    javaCheckBox->setChecked(true);
    ftpLineEdit->setEnabled(false);
}
