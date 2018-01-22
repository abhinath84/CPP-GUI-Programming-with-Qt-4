#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "CGFindDialog.h"

CGFindDialog::CGFindDialog(QWidget *parent)
    :QDialog(parent),
      extension(new QWidget()),
      lblFindWhat(new QLabel()),
      txtFindWhat(new QLineEdit()),
      chkMatchCase(new QCheckBox()),
      chkSearchFromStart(new QCheckBox()),
      chkSearchBackward(new QCheckBox()),
      chkWholeWords(new QCheckBox()),
      chkSearchSelection(new QCheckBox()),
      btnBox(new QDialogButtonBox(Qt::Vertical)),
      btnFind(new QPushButton()),
      btnCancel(new QPushButton()),
      btnMore(new QPushButton())
{
    // Set properies of the widgets used Find Dialog.
    lblFindWhat->setText(tr("&Find What:"));
    lblFindWhat->setBuddy(txtFindWhat);

    chkMatchCase->setText(tr("Match &case"));
    chkSearchFromStart->setText(tr("Search from &start"));
    chkSearchFromStart->setChecked(true);
    chkSearchBackward->setText(tr("Search &backward"));
    chkWholeWords->setText(tr("&Whole words"));
    chkSearchSelection->setText(tr("Search se&lection"));

    btnFind->setText(tr("Find"));
    btnFind->setDefault(true);
    btnFind->setEnabled(false);

    btnCancel->setText(tr("Cancel"));

    btnMore->setText(tr("&More"));
    btnMore->setCheckable(true);
    btnMore->setAutoDefault(false);

    btnBox->addButton(btnFind, QDialogButtonBox::ActionRole);
    btnBox->addButton(btnCancel, QDialogButtonBox::ActionRole);
    btnBox->addButton(btnMore, QDialogButtonBox::ActionRole);

    extension->hide();

    // Connect widgets through Signals & slots.
    connect(txtFindWhat, &QLineEdit::textChanged,
            this, &CGFindDialog::enableFindButton);
    connect(btnFind, &QPushButton::clicked,
            this, &CGFindDialog::findClicked);
    connect(btnCancel, &QPushButton::clicked,
            this, &CGFindDialog::reject);
    connect(btnMore, &QPushButton::toggled,
            extension, &QWidget::setVisible);

    // Design Find Dialog by proper arrangement of widgets.
    QHBoxLayout *hloTopLeft = new QHBoxLayout();
    hloTopLeft->addWidget(lblFindWhat);
    hloTopLeft->addWidget(txtFindWhat);

    QVBoxLayout *vloLeft = new QVBoxLayout();
    vloLeft->addLayout(hloTopLeft);
    vloLeft->addWidget(chkMatchCase);
    vloLeft->addWidget(chkSearchFromStart);

    QVBoxLayout *vloExtension = new QVBoxLayout();
    vloExtension->setMargin(0);
    vloExtension->addWidget(chkSearchBackward);
    vloExtension->addWidget(chkWholeWords);
    vloExtension->addWidget(chkSearchSelection);

    extension->setLayout(vloExtension);

    QGridLayout *gloMain = new QGridLayout();
    gloMain->setSizeConstraint(QLayout::SetFixedSize);
    gloMain->addLayout(vloLeft, 0, 0);
    gloMain->addWidget(btnBox, 0, 1);
    gloMain->addWidget(extension, 1, 0, 1, 2);
    gloMain->setRowStretch(2, 1);

    setLayout(gloMain);
    setWindowTitle(tr("Find"));
}

CGFindDialog::~CGFindDialog()
{

}

void CGFindDialog::findClicked()
{
    QString text = txtFindWhat->text();
    Qt::CaseSensitivity cs = chkSearchBackward->isChecked() ?
                                Qt::CaseSensitive : Qt::CaseInsensitive;

    if (chkSearchBackward->isChecked())
    {
        emit findPrevious(text, cs);
    }
    else
    {
        emit findNext(text, cs);
    }
}

void CGFindDialog::enableFindButton(const QString &text)
{
    btnFind->setEnabled(!text.isEmpty());
}
