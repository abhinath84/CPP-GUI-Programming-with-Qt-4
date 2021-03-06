#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

class QGroupBox;
class QGridLayout;
class QLabel;
class QDialogButtonBox;
class QPushButton;
class QComboBox;
class QSpacerItem;

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);

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

#endif // SORTDIALOG_H
