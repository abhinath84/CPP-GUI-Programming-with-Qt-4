#include "cgwebbrowserpage.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

CGWebBrowserPage::CGWebBrowserPage(QWidget *parent)
    : QWidget(parent)
{
    displayGroupBox = new QGroupBox(tr("Display on startup"));
    blankRadioButton = new QRadioButton(tr("Blank page"));
    homeRadioButton = new QRadioButton(tr("Blank page"));
    lastRadioButton = new QRadioButton(tr("Last page visited"));

    homeGroupBox = new QGroupBox(tr("Home Page"));
    locationLabel = new QLabel(tr("Location:"));
    locationLineEdit = new QLineEdit;

    webButtonsGroupBox = new QGroupBox(tr("Select the buttons you want "
                                          "in the toolbar"));
    bookmarksCheckBox = new QCheckBox(tr("Bookmarks"));
    goCheckBox = new QCheckBox(tr("Go"));
    homeCheckBox = new QCheckBox(tr("Home"));
    searchCheckBox = new QCheckBox(tr("Search"));
    printCheckBox = new QCheckBox(tr("Print"));

    QVBoxLayout *displayLayout = new QVBoxLayout;
    displayLayout->addWidget(blankRadioButton);
    displayLayout->addWidget(homeRadioButton);
    displayLayout->addWidget(lastRadioButton);
    displayGroupBox->setLayout(displayLayout);

    QHBoxLayout *homeLayout = new QHBoxLayout;
    homeLayout->addWidget(locationLabel);
    homeLayout->addWidget(locationLineEdit);
    homeGroupBox->setLayout(homeLayout);

    QGridLayout *webButtonsLayout = new QGridLayout;
    webButtonsLayout->addWidget(bookmarksCheckBox, 0, 0);
    webButtonsLayout->addWidget(goCheckBox, 1, 0);
    webButtonsLayout->addWidget(homeCheckBox, 2, 0);
    webButtonsLayout->addWidget(searchCheckBox, 0, 1);
    webButtonsLayout->addWidget(printCheckBox, 1, 1);
    webButtonsGroupBox->setLayout(webButtonsLayout);

    QVBoxLayout *pageLayout = new QVBoxLayout;
    pageLayout->setMargin(0);
    pageLayout->addWidget(displayGroupBox);
    pageLayout->addWidget(homeGroupBox);
    pageLayout->addWidget(webButtonsGroupBox);
    pageLayout->addStretch();
    this->setLayout(pageLayout);

    homeRadioButton->setChecked(true);
    locationLineEdit->setText("http://www.trolltech.com/");
    bookmarksCheckBox->setChecked(true);
    homeCheckBox->setChecked(true);
    searchCheckBox->setChecked(true);
    printCheckBox->setChecked(true);
}
