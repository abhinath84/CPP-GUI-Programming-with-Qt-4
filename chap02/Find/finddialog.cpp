#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "finddialog.h"

/*
 * Parent & child hierarchy of Find dialog widgets.
 *
 *      FindDialog
 *          |-------QLabel (lblFindWhat)
 *          |-------QLineEdit (txtFind)
 *          |-------QCheckBox (chkboxCase)
 *          |-------QCheckBox (chkboxBackward)
 *          |-------QPushButton (btnFind)
 *          |-------QPushButton (btnClose)
 *          |-------QHBoxLaout (hloMain)
 *                         |-------QVBoxLayout (vloLeft)
 *                         |              |----QHBoxLayout (hloTopLeft)
 *                         |-------QVBoxLayout (vloRight)
*/

FindDialog::FindDialog(QWidget *parent)
    :QDialog(parent),
      lblFindWhat(new QLabel(tr("Find &What:"))),
      txtFind(new QLineEdit()),
      chkboxCase(new QCheckBox(tr("Match &case"))),
      chkboxFromStart(new QCheckBox(tr("Search from &start"))),
      chkboxBackward(new QCheckBox(tr("Search &backward"))),
      chkboxWholeWords(new QCheckBox(tr("&Whole words"))),
      chkboxSearchSelection(new QCheckBox(tr("Search se&lection"))),
      btnBox(new QDialogButtonBox(Qt::Vertical)),
      btnFind(new QPushButton(tr("&Find"))),
      btnClose(new QPushButton(tr("Close"))),
      btnMore(new QPushButton(tr("&More"))),
      extension(new QWidget())
{
    // Set properties of widgets.
    lblFindWhat->setBuddy(txtFind);
    chkboxFromStart->setChecked(true);

    btnFind->setDefault(true);
    btnFind->setEnabled(false);

    btnMore->setCheckable(true);
    btnMore->setAutoDefault(false);

    btnBox->addButton(btnFind, QDialogButtonBox::ActionRole);
    btnBox->addButton(btnClose, QDialogButtonBox::ActionRole);
    btnBox->addButton(btnMore, QDialogButtonBox::ActionRole);


    // Connect between Signal & Slot
    QObject::connect(txtFind, SIGNAL(textChanged(const QString &)),
                     this, SLOT(enableFindButton(const QString &)));
    QObject::connect(btnFind, SIGNAL(clicked()),
                     this, SLOT(findClicked()));
    QObject::connect(btnClose, SIGNAL(clicked()),
                     this, SLOT(close()));
    QObject::connect(btnMore, &QAbstractButton::toggled,
                     extension, &QWidget::setVisible);

    // Design Find dialog by arranging widgets properly.
    QVBoxLayout *vloExtension = new QVBoxLayout();
    vloExtension->setMargin(0);
    vloExtension->addWidget(chkboxBackward);
    vloExtension->addWidget(chkboxWholeWords);
    vloExtension->addWidget(chkboxSearchSelection);

    extension->setLayout(vloExtension);
    extension->hide();

    QHBoxLayout *hloTopLeft = new QHBoxLayout();
    hloTopLeft->addWidget(lblFindWhat);
    hloTopLeft->addWidget(txtFind);

    QVBoxLayout *vloLeft    = new QVBoxLayout();
    vloLeft->addLayout(hloTopLeft);
    vloLeft->addWidget(chkboxCase);
    vloLeft->addWidget(chkboxFromStart);

    QGridLayout *gloMain    = new QGridLayout();
    gloMain->setSizeConstraint(QLayout::SetFixedSize);
    gloMain->addLayout(vloLeft, 0, 0);
    gloMain->addWidget(btnBox, 0, 1);
    gloMain->addWidget(extension, 1, 0, 1, 2);
    gloMain->setRowStretch(2, 1);

    setLayout(gloMain);
    setWindowTitle(tr("Find"));
}

void FindDialog::findClicked()
{
    QString strfind = txtFind->text();
    Qt::CaseSensitivity cs = chkboxCase->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if(chkboxBackward->isChecked())
    {
        emit findPrevious(strfind, cs);
    }
    else
    {
        emit findNext(strfind, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    btnFind->setEnabled(!text.isEmpty());
}
