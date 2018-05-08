#include <QtGui>

#include <QListWidget>
#include <QStackedLayout>
#include <QDialogButtonBox>

#include "cgadvancedpage.h"
#include "cgappearancepage.h"
#include "cgwebbrowserpage.h"
#include "cgmailandnewspage.h"
#include "cgpreferencedialog.h"


CGPreferenceDialog::CGPreferenceDialog(QWidget *parent)
    : QDialog(parent)
{
    // Initialize ListWidget pages.
    appearancePage = new CGAppearancePage;
    webBrowserPage = new CGWebBrowserPage;
    mailAndNewsPage = new CGMailAndNewsPage;
    advancedPage = new CGAdvancedPage;

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    listWidget = new QListWidget;
    listWidget->addItem(tr("Appearance"));
    listWidget->addItem(tr("Web Browser"));
    listWidget->addItem(tr("Mail & News"));
    listWidget->addItem(tr("Advanced"));

    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(appearancePage);
    stackedLayout->addWidget(webBrowserPage);
    stackedLayout->addWidget(mailAndNewsPage);
    stackedLayout->addWidget(advancedPage);
    connect(listWidget, SIGNAL(currentRowChanged(int)),
            stackedLayout, SLOT(setCurrentIndex(int)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 3);
    mainLayout->addWidget(listWidget, 0, 0);
    mainLayout->addLayout(stackedLayout, 0, 1);
    mainLayout->addWidget(buttonBox, 1, 0, 1, 2);
    setLayout(mainLayout);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    setWindowTitle(tr("Preferences"));
    listWidget->setCurrentRow(0);
}
