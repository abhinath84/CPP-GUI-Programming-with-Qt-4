#include "cgfindfiledialog.h"

#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>


/*
 * The layout is handled by one QHBoxLayout , one QGridLayout , and one QVBoxLayout .
 * The QGridLayout on the left and the QVBoxLayout on the right are placed side by
 * side by the outer QHBoxLayout . The margin around the dialog and the spacing
 * between the child widgets are set to default values based on the current
 * widget style; they can be changed using QLayout::setMargin() and QLayout::setSpacing() .
*/
CGFindFileDialog::CGFindFileDialog(QWidget *parent)
    : QDialog(parent)
{
    namedLabel = new QLabel(tr("&Named:"));
    namedLineEdit = new QLineEdit;
    namedLabel->setBuddy(namedLineEdit);

    lookInLabel = new QLabel(tr("&Look in:"));
    lookInLineEdit = new QLineEdit;
    lookInLabel->setBuddy(lookInLineEdit);

    subfoldersCheckBox = new QCheckBox(tr("Include subfolders"));

    QStringList labels;
    labels << tr("Name") << tr("In Folder") << tr("Size")
           << tr("Modified");

    tableWidget = new QTableWidget;
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(labels);

    messageLabel = new QLabel(tr("0 files found"));
    messageLabel->setFrameShape(QLabel::Panel);
    messageLabel->setFrameShadow(QLabel::Sunken);

    findButton = new QPushButton(tr("&Find"));
    stopButton = new QPushButton(tr("Stop"));
    closeButton = new QPushButton(tr("Close"));
    helpButton = new QPushButton(tr("Help"));

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(namedLabel, 0, 0);
    leftLayout->addWidget(namedLineEdit, 0, 1);
    leftLayout->addWidget(lookInLabel, 1, 0);
    leftLayout->addWidget(lookInLineEdit, 1, 1);
    leftLayout->addWidget(subfoldersCheckBox, 2, 0, 1, 2);
    leftLayout->addWidget(tableWidget, 3, 0, 1, 2);
    leftLayout->addWidget(messageLabel, 4, 0, 1, 2);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(stopButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();
    rightLayout->addWidget(helpButton);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find Files or Folders"));
}
