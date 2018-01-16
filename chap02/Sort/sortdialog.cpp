#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    :QDialog(parent),
      ui(new Ui::SortDialog())
{
    ui->setupUi(this);

    ui->grpSecondaryKey->hide();
    ui->grpTertiaryKey->hide();

    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
    if(ui)
        delete ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->cmbPrimaryKeyColumn->clear();
    ui->cmbSecondaryKeyColumn->clear();
    ui->cmbTertiaryKeyColumn->clear();

    ui->cmbSecondaryKeyColumn->addItem(tr("None"));
    ui->cmbTertiaryKeyColumn->addItem(tr("None"));

    ui->cmbPrimaryKeyColumn->setMinimumSize(
                ui->cmbSecondaryKeyColumn->sizeHint());

    QChar ch = first;
    while (ch <= last)
    {
        ui->cmbPrimaryKeyColumn->addItem(QString(ch));
        ui->cmbSecondaryKeyColumn->addItem(QString(ch));
        ui->cmbTertiaryKeyColumn->addItem(QString(ch));

        ch = ch.unicode() + 1;
    }
}
