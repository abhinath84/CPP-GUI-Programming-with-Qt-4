#ifndef CGSORTDIALOG_H
#define CGSORTDIALOG_H

#include <QDialog>

class QGroupBox;
class QGridLayout;
class QLabel;
class QDialogButtonBox;
class QPushButton;
class QComboBox;
class QSpacerItem;

class CGSortDialog : public QDialog
{
    Q_OBJECT

public:
    CGSortDialog(QWidget *parent = 0);

    int PrimaryColumnCurrentIndex() const;
    int PrimaryOrderCurrentIndex() const;

    QString PrimaryColumnText() const;
    QString PrimaryOrderText() const;

    int SecondaryColumnCurrentIndex() const;
    int SecondaryOrderCurrentIndex() const;

    QString SecondaryColumnText() const;
    QString SecondaryOrderText() const;

    int TertiaryColumnCurrentIndex() const;
    int TertiaryOrderCurrentIndex() const;

    QString TertiaryColumnText() const;
    QString TertiaryOrderText() const;

    void setColumnRange(QChar first, QChar last);

private:
    QWidget             *extension;
    QGroupBox           *grpPrimaryKey;
    QGroupBox           *grpSecondaryKey;
    QGroupBox           *grpTertiaryKey;
    QGridLayout         *gloPrimaryKey;
    QGridLayout         *gloSecondaryKey;
    QGridLayout         *gloTertiaryKey;
    QLabel              *lblPrimaryKeyColumn;
    QLabel              *lblPrimaryKeyOrder;
    QLabel              *lblSecondaryKeyColumn;
    QLabel              *lblSecondaryKeyOrder;
    QLabel              *lblTertiaryKeyColumn;
    QLabel              *lblTertiaryKeyOrder;
    QComboBox           *cmbPrimaryKeyColumn;
    QComboBox           *cmbPrimaryKeyOrder;
    QComboBox           *cmbSecondaryKeyColumn;
    QComboBox           *cmbSecondaryKeyOrder;
    QComboBox           *cmbTertiaryKeyColumn;
    QComboBox           *cmbTertiaryKeyOrder;
    QSpacerItem         *hpcrPrimaryKey;
    QSpacerItem         *hpcrSecondaryKey;
    QSpacerItem         *hpcrTertiaryKey;
    QDialogButtonBox    *btnbox;
    QPushButton         *btnOk;
    QPushButton         *btnCancel;
    QPushButton         *btnMore;
};

#endif // CGSORTDIALOG_H
