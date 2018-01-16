/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *grpPrimaryKey;
    QGridLayout *gridLayout;
    QLabel *lblColumn;
    QComboBox *cmbPrimaryKeyColumn;
    QSpacerItem *horizontalSpacer;
    QLabel *lblOrder;
    QComboBox *cmbPrimaryKeyOrder;
    QSpacerItem *verticalSpacer;
    QGroupBox *grpSecondaryKey;
    QGridLayout *gridLayout_2;
    QLabel *lblColumn_2;
    QComboBox *cmbSecondaryKeyColumn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblOrder_2;
    QComboBox *cmbSecondaryKeyOrder;
    QGroupBox *grpTertiaryKey;
    QGridLayout *gridLayout_3;
    QLabel *lblColumn_3;
    QComboBox *cmbTertiaryKeyColumn;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblOrder_3;
    QComboBox *cmbTertiaryKeyOrder;
    QVBoxLayout *verticalLayout;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnMore;
    QGroupBox *groupBox;
    QComboBox *cmbPrimaryKeyColumn_2;
    QLabel *lblColumn_4;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QStringLiteral("SortDialog"));
        SortDialog->resize(324, 362);
        gridLayout_4 = new QGridLayout(SortDialog);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        grpPrimaryKey = new QGroupBox(SortDialog);
        grpPrimaryKey->setObjectName(QStringLiteral("grpPrimaryKey"));
        gridLayout = new QGridLayout(grpPrimaryKey);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblColumn = new QLabel(grpPrimaryKey);
        lblColumn->setObjectName(QStringLiteral("lblColumn"));

        gridLayout->addWidget(lblColumn, 0, 0, 1, 1);

        cmbPrimaryKeyColumn = new QComboBox(grpPrimaryKey);
        cmbPrimaryKeyColumn->addItem(QString());
        cmbPrimaryKeyColumn->setObjectName(QStringLiteral("cmbPrimaryKeyColumn"));

        gridLayout->addWidget(cmbPrimaryKeyColumn, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        lblOrder = new QLabel(grpPrimaryKey);
        lblOrder->setObjectName(QStringLiteral("lblOrder"));

        gridLayout->addWidget(lblOrder, 1, 0, 1, 1);

        cmbPrimaryKeyOrder = new QComboBox(grpPrimaryKey);
        cmbPrimaryKeyOrder->addItem(QString());
        cmbPrimaryKeyOrder->addItem(QString());
        cmbPrimaryKeyOrder->setObjectName(QStringLiteral("cmbPrimaryKeyOrder"));

        gridLayout->addWidget(cmbPrimaryKeyOrder, 1, 1, 1, 2);


        gridLayout_4->addWidget(grpPrimaryKey, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        grpSecondaryKey = new QGroupBox(SortDialog);
        grpSecondaryKey->setObjectName(QStringLiteral("grpSecondaryKey"));
        gridLayout_2 = new QGridLayout(grpSecondaryKey);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblColumn_2 = new QLabel(grpSecondaryKey);
        lblColumn_2->setObjectName(QStringLiteral("lblColumn_2"));

        gridLayout_2->addWidget(lblColumn_2, 0, 0, 1, 1);

        cmbSecondaryKeyColumn = new QComboBox(grpSecondaryKey);
        cmbSecondaryKeyColumn->addItem(QString());
        cmbSecondaryKeyColumn->setObjectName(QStringLiteral("cmbSecondaryKeyColumn"));

        gridLayout_2->addWidget(cmbSecondaryKeyColumn, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        lblOrder_2 = new QLabel(grpSecondaryKey);
        lblOrder_2->setObjectName(QStringLiteral("lblOrder_2"));

        gridLayout_2->addWidget(lblOrder_2, 1, 0, 1, 1);

        cmbSecondaryKeyOrder = new QComboBox(grpSecondaryKey);
        cmbSecondaryKeyOrder->addItem(QString());
        cmbSecondaryKeyOrder->addItem(QString());
        cmbSecondaryKeyOrder->setObjectName(QStringLiteral("cmbSecondaryKeyOrder"));

        gridLayout_2->addWidget(cmbSecondaryKeyOrder, 1, 1, 1, 2);


        gridLayout_4->addWidget(grpSecondaryKey, 2, 0, 1, 1);

        grpTertiaryKey = new QGroupBox(SortDialog);
        grpTertiaryKey->setObjectName(QStringLiteral("grpTertiaryKey"));
        gridLayout_3 = new QGridLayout(grpTertiaryKey);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblColumn_3 = new QLabel(grpTertiaryKey);
        lblColumn_3->setObjectName(QStringLiteral("lblColumn_3"));

        gridLayout_3->addWidget(lblColumn_3, 0, 0, 1, 1);

        cmbTertiaryKeyColumn = new QComboBox(grpTertiaryKey);
        cmbTertiaryKeyColumn->addItem(QString());
        cmbTertiaryKeyColumn->setObjectName(QStringLiteral("cmbTertiaryKeyColumn"));

        gridLayout_3->addWidget(cmbTertiaryKeyColumn, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        lblOrder_3 = new QLabel(grpTertiaryKey);
        lblOrder_3->setObjectName(QStringLiteral("lblOrder_3"));

        gridLayout_3->addWidget(lblOrder_3, 1, 0, 1, 1);

        cmbTertiaryKeyOrder = new QComboBox(grpTertiaryKey);
        cmbTertiaryKeyOrder->addItem(QString());
        cmbTertiaryKeyOrder->addItem(QString());
        cmbTertiaryKeyOrder->setObjectName(QStringLiteral("cmbTertiaryKeyOrder"));

        gridLayout_3->addWidget(cmbTertiaryKeyOrder, 1, 1, 1, 2);


        gridLayout_4->addWidget(grpTertiaryKey, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnOk = new QPushButton(SortDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setCheckable(false);

        verticalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(SortDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setCheckable(false);
        btnCancel->setAutoDefault(true);

        verticalLayout->addWidget(btnCancel);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnMore = new QPushButton(SortDialog);
        btnMore->setObjectName(QStringLiteral("btnMore"));
        btnMore->setCheckable(true);
        btnMore->setAutoDefault(true);

        verticalLayout->addWidget(btnMore);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        groupBox = new QGroupBox(SortDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        cmbPrimaryKeyColumn_2 = new QComboBox(groupBox);
        cmbPrimaryKeyColumn_2->addItem(QString());
        cmbPrimaryKeyColumn_2->setObjectName(QStringLiteral("cmbPrimaryKeyColumn_2"));
        cmbPrimaryKeyColumn_2->setGeometry(QRect(45, 20, 51, 20));
        lblColumn_4 = new QLabel(groupBox);
        lblColumn_4->setObjectName(QStringLiteral("lblColumn_4"));
        lblColumn_4->setGeometry(QRect(0, 20, 39, 20));

        gridLayout_4->addWidget(groupBox, 2, 1, 1, 1);

        QWidget::setTabOrder(cmbPrimaryKeyColumn, cmbPrimaryKeyOrder);
        QWidget::setTabOrder(cmbPrimaryKeyOrder, cmbSecondaryKeyColumn);
        QWidget::setTabOrder(cmbSecondaryKeyColumn, cmbSecondaryKeyOrder);
        QWidget::setTabOrder(cmbSecondaryKeyOrder, cmbTertiaryKeyColumn);
        QWidget::setTabOrder(cmbTertiaryKeyColumn, cmbTertiaryKeyOrder);
        QWidget::setTabOrder(cmbTertiaryKeyOrder, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, btnMore);

        retranslateUi(SortDialog);
        QObject::connect(btnOk, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(btnMore, SIGNAL(toggled(bool)), grpSecondaryKey, SLOT(setVisible(bool)));
        QObject::connect(btnMore, SIGNAL(toggled(bool)), grpTertiaryKey, SLOT(setVisible(bool)));

        btnOk->setDefault(true);
        btnCancel->setDefault(false);
        btnMore->setDefault(false);


        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Dialog", nullptr));
        grpPrimaryKey->setTitle(QApplication::translate("SortDialog", "&Primary Key", nullptr));
        lblColumn->setText(QApplication::translate("SortDialog", "Column:", nullptr));
        cmbPrimaryKeyColumn->setItemText(0, QApplication::translate("SortDialog", "None", nullptr));

        lblOrder->setText(QApplication::translate("SortDialog", "Order:", nullptr));
        cmbPrimaryKeyOrder->setItemText(0, QApplication::translate("SortDialog", "Ascending", nullptr));
        cmbPrimaryKeyOrder->setItemText(1, QApplication::translate("SortDialog", "Descending", nullptr));

        grpSecondaryKey->setTitle(QApplication::translate("SortDialog", "&Secondary Key", nullptr));
        lblColumn_2->setText(QApplication::translate("SortDialog", "Column:", nullptr));
        cmbSecondaryKeyColumn->setItemText(0, QApplication::translate("SortDialog", "None", nullptr));

        lblOrder_2->setText(QApplication::translate("SortDialog", "Order:", nullptr));
        cmbSecondaryKeyOrder->setItemText(0, QApplication::translate("SortDialog", "Ascending", nullptr));
        cmbSecondaryKeyOrder->setItemText(1, QApplication::translate("SortDialog", "Descending", nullptr));

        grpTertiaryKey->setTitle(QApplication::translate("SortDialog", "&Tertiary Key", nullptr));
        lblColumn_3->setText(QApplication::translate("SortDialog", "Column:", nullptr));
        cmbTertiaryKeyColumn->setItemText(0, QApplication::translate("SortDialog", "None", nullptr));

        lblOrder_3->setText(QApplication::translate("SortDialog", "Order:", nullptr));
        cmbTertiaryKeyOrder->setItemText(0, QApplication::translate("SortDialog", "Ascending", nullptr));
        cmbTertiaryKeyOrder->setItemText(1, QApplication::translate("SortDialog", "Descending", nullptr));

        btnOk->setText(QApplication::translate("SortDialog", "&OK", nullptr));
        btnCancel->setText(QApplication::translate("SortDialog", "&Cancel", nullptr));
        btnMore->setText(QApplication::translate("SortDialog", "&More", nullptr));
        groupBox->setTitle(QApplication::translate("SortDialog", "GroupBox", nullptr));
        cmbPrimaryKeyColumn_2->setItemText(0, QApplication::translate("SortDialog", "None", nullptr));

        lblColumn_4->setText(QApplication::translate("SortDialog", "Column:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
