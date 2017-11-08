/********************************************************************************
** Form generated from reading UI file 'dishdialog.ui'
**
** Created: Mon 6. Nov 18:29:28 2017
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHDIALOG_H
#define UI_DISHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DishDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *DishDialog)
    {
        if (DishDialog->objectName().isEmpty())
            DishDialog->setObjectName(QString::fromUtf8("DishDialog"));
        DishDialog->resize(263, 339);
        verticalLayout = new QVBoxLayout(DishDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(DishDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(DishDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DishDialog);

        QMetaObject::connectSlotsByName(DishDialog);
    } // setupUi

    void retranslateUi(QDialog *DishDialog)
    {
        DishDialog->setWindowTitle(QApplication::translate("DishDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DishDialog", "Save Changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DishDialog: public Ui_DishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHDIALOG_H
