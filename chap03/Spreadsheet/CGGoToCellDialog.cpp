#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRegExpValidator>

#include "CGGoToCellDialog.h"

/*
 * Parent & child hierarchy of Find dialog widgets.
 *
 *      FindDialog
 *          |-------QLabel (lblCellLoc)
 *          |-------QLineEdit (txtLoc)
 *          |-------QPushButton (btnOk)
 *          |-------QPushButton (btnCancel)
 *          |-------QVBoxLayout (vloMain)
 *                         |-------QHBoxLayout (hloTop)
 *                         |-------QHBoxLayout (hloButtom)
*/

CGGoToCellDialog::CGGoToCellDialog(QWidget *parent)
    :QDialog(parent),
      lblCellLoc(new QLabel(tr("&Cell Location:"))),
      txtLoc(new QLineEdit()),
      btnOk(new QPushButton(tr("&OK"))),
      btnCancel(new QPushButton(tr("Cancel")))
{
    // Set properties of widgets.
    lblCellLoc->setBuddy(txtLoc);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    txtLoc->setValidator(new QRegExpValidator(regExp, this));

    btnOk->setDefault(true);
    btnOk->setEnabled(false);

    // Connect Between Signal & Slot
    QObject::connect(txtLoc, SIGNAL(textChanged(const QString &)),
                     this, SLOT(on_lineEdit_textChanged()));
    QObject::connect(btnOk, SIGNAL(clicked(bool)),
                     this, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked(bool)),
                     this, SLOT(reject()));

    // Design Find dialog by arranging widgets properly.
    QHBoxLayout *hloTop = new QHBoxLayout();
    hloTop->addWidget(lblCellLoc);
    hloTop->addWidget(txtLoc);

    QHBoxLayout *hloButtom = new QHBoxLayout();
    hloButtom->addStretch();
    hloButtom->addWidget(btnOk);
    hloButtom->addWidget(btnCancel);

    QVBoxLayout *vloMain = new QVBoxLayout();
    vloMain->setSizeConstraint(QLayout::SetFixedSize);
    vloMain->addLayout(hloTop);
    vloMain->addLayout(hloButtom);

    setLayout(vloMain);
    setWindowTitle("Go To Cell");
}

CGGoToCellDialog::~CGGoToCellDialog()
{
    delete lblCellLoc;
    delete txtLoc;
    delete btnOk;
    delete btnCancel;
}

void CGGoToCellDialog::on_lineEdit_textChanged()
{
    btnOk->setEnabled( txtLoc->hasAcceptableInput() );
}
