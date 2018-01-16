#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    :QDialog(parent),
      ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->txtLoc->setValidator(new QRegExpValidator(regExp, this));

    QObject::connect(ui->btnOk, SIGNAL(clicked()),
                     this, SLOT(accept()));
    QObject::connect(ui->btnCancel, SIGNAL(clicked()),
                     this, SLOT(reject()));
    QObject::connect(ui->txtLoc, SIGNAL(textChanged(const QString &)),
                     this, SLOT(on_lineEdit_textChanged()));

    setFixedSize(width(), height());
}

GoToCellDialog::~GoToCellDialog()
{
    if(ui)
        delete ui;
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    ui->btnOk->setEnabled( ui->txtLoc->hasAcceptableInput() );
}
