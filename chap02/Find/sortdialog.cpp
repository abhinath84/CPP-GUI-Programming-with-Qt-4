#include <QGroupBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "sortdialog.h"


SortDialog::SortDialog(QWidget *parent)
    :QDialog(parent),
      extension(new QWidget()),
      grpPrimaryKey(new QGroupBox()),
      grpSecondaryKey(new QGroupBox()),
      grpTertiaryKey(new QGroupBox()),
      gloPrimaryKey(new QGridLayout(grpPrimaryKey)),
      gloSecondaryKey(new QGridLayout(grpSecondaryKey)),
      gloTertiaryKey(new QGridLayout(grpTertiaryKey)),
      lblPrimaryKeyColumn(new QLabel()),
      lblPrimaryKeyOrder(new QLabel()),
      lblSecondaryKeyColumn(new QLabel()),
      lblSecondaryKeyOrder(new QLabel()),
      lblTertiaryKeyColumn(new QLabel()),
      lblTertiaryKeyOrder(new QLabel()),
      cmbPrimaryKeyColumn(new QComboBox()),
      cmbPrimaryKeyOrder(new QComboBox()),
      cmbSecondaryKeyColumn(new QComboBox()),
      cmbSecondaryKeyOrder(new QComboBox()),
      cmbTertiaryKeyColumn(new QComboBox()),
      cmbTertiaryKeyOrder(new QComboBox()),
      hpcrPrimaryKey(new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum)),
      hpcrSecondaryKey(new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum)),
      hpcrTertiaryKey(new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum)),
      btnbox(new QDialogButtonBox(Qt::Vertical)),
      btnOk(new QPushButton()),
      btnCancel(new QPushButton()),
      btnMore(new QPushButton())
{
    // Set properties of widgets.
    // Primary Key Group
    grpPrimaryKey->setTitle(tr("&Primary Key"));

    lblPrimaryKeyColumn->setText(tr("Column:"));
    lblPrimaryKeyColumn->setBuddy(cmbPrimaryKeyColumn);

    lblPrimaryKeyOrder->setText(tr("Order:"));
    lblPrimaryKeyOrder->setBuddy(cmbPrimaryKeyOrder);

    cmbPrimaryKeyColumn->addItem(tr("None"));

    cmbPrimaryKeyOrder->addItem(tr("Ascending"));
    cmbPrimaryKeyOrder->addItem(tr("Descending"));

    gloPrimaryKey->addWidget(lblPrimaryKeyColumn, 0, 0, 1, 1);
    gloPrimaryKey->addWidget(cmbPrimaryKeyColumn, 0, 1, 1, 1);
    gloPrimaryKey->addItem(hpcrPrimaryKey, 0, 2, 1, 1);
    gloPrimaryKey->addWidget(lblPrimaryKeyOrder, 1, 0, 1, 1);
    gloPrimaryKey->addWidget(cmbPrimaryKeyOrder, 1, 1, 1, 2);

    // Secondary Key Group
    grpSecondaryKey->setTitle(tr("&Secondary Key"));

    lblSecondaryKeyColumn->setText(tr("Column:"));
    lblSecondaryKeyColumn->setBuddy(cmbSecondaryKeyColumn);

    lblSecondaryKeyOrder->setText(tr("Order:"));
    lblSecondaryKeyOrder->setBuddy(cmbSecondaryKeyOrder);

    cmbSecondaryKeyColumn->addItem(tr("None"));

    cmbSecondaryKeyOrder->addItem(tr("Ascending"));
    cmbSecondaryKeyOrder->addItem(tr("Descending"));

    gloSecondaryKey->addWidget(lblSecondaryKeyColumn, 0, 0, 1, 1);
    gloSecondaryKey->addWidget(cmbSecondaryKeyColumn, 0, 1, 1, 1);
    gloSecondaryKey->addItem(hpcrSecondaryKey, 0, 2, 1, 1);
    gloSecondaryKey->addWidget(lblSecondaryKeyOrder, 1, 0, 1, 1);
    gloSecondaryKey->addWidget(cmbSecondaryKeyOrder, 1, 1, 1, 2);

    // Tertiary Key Group
    grpTertiaryKey->setTitle(tr("&Tertiary Key"));

    lblTertiaryKeyColumn->setText(tr("Column:"));
    lblTertiaryKeyColumn->setBuddy(cmbTertiaryKeyColumn);

    lblTertiaryKeyOrder->setText(tr("Order:"));
    lblTertiaryKeyOrder->setBuddy(cmbTertiaryKeyOrder);

    cmbTertiaryKeyColumn->addItem(tr("None"));

    cmbTertiaryKeyOrder->addItem(tr("Ascending"));
    cmbTertiaryKeyOrder->addItem(tr("Descending"));

    gloTertiaryKey->addWidget(lblTertiaryKeyColumn, 0, 0, 1, 1);
    gloTertiaryKey->addWidget(cmbTertiaryKeyColumn, 0, 1, 1, 1);
    gloTertiaryKey->addItem(hpcrTertiaryKey, 0, 2, 1, 1);
    gloTertiaryKey->addWidget(lblTertiaryKeyOrder, 1, 0, 1, 1);
    gloTertiaryKey->addWidget(cmbTertiaryKeyOrder, 1, 1, 1, 2);

    // Buttons
    btnOk->setText(tr("&OK"));
    btnOk->setDefault(true);
    btnCancel->setText(tr("&Cancel"));
    btnMore->setText(tr("&More"));
    btnMore->setCheckable(true);
    btnMore->setAutoDefault(false);

    btnbox->addButton(btnOk, QDialogButtonBox::ActionRole);
    btnbox->addButton(btnCancel, QDialogButtonBox::ActionRole);
    btnbox->addButton(btnMore, QDialogButtonBox::ActionRole);

    connect(btnOk, &QAbstractButton::clicked,
            this, &SortDialog::accept);
    connect(btnCancel, &QAbstractButton::clicked,
            this, &SortDialog::reject);
    connect(btnMore, &QAbstractButton::toggled,
            extension, &QWidget::setVisible);

    // Design Sort dialog by arranging widgets.
    QVBoxLayout *vloExtension = new QVBoxLayout();
    vloExtension->setMargin(0);
    vloExtension->addWidget(grpSecondaryKey);
    vloExtension->addWidget(grpTertiaryKey);

    extension->setLayout(vloExtension);
    extension->hide();

    QGridLayout *gloMain = new QGridLayout();
    gloMain->setSizeConstraint(QLayout::SetFixedSize);
    gloMain->addWidget(grpPrimaryKey, 0, 0);
    gloMain->addWidget(btnbox, 0, 1);
    gloMain->addWidget(extension, 1, 0, 1, 1);
    gloMain->setRowStretch(2, 1);

    setLayout(gloMain);
    setWindowTitle(tr("Sort"));
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    cmbPrimaryKeyColumn->clear();
    cmbSecondaryKeyColumn->clear();
    cmbTertiaryKeyColumn->clear();

    cmbSecondaryKeyColumn->addItem(tr("None"));
    cmbTertiaryKeyColumn->addItem(tr("None"));

    cmbPrimaryKeyColumn->setMinimumSize(cmbSecondaryKeyColumn->sizeHint());

    QChar ch = first;
    while (ch <= last)
    {
        cmbPrimaryKeyColumn->addItem(QString(ch));
        cmbSecondaryKeyColumn->addItem(QString(ch));
        cmbTertiaryKeyColumn->addItem(QString(ch));

        ch = ch.unicode() + 1;
    }
}
