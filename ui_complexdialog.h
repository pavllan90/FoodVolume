/********************************************************************************
** Form generated from reading UI file 'complexdialog.ui'
**
** Created: Mon 6. Nov 18:23:15 2017
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPLEXDIALOG_H
#define UI_COMPLEXDIALOG_H

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

class Ui_ComplexDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ComplexDialog)
    {
        if (ComplexDialog->objectName().isEmpty())
            ComplexDialog->setObjectName(QString::fromUtf8("ComplexDialog"));
        ComplexDialog->resize(560, 339);
        verticalLayout = new QVBoxLayout(ComplexDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ComplexDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(ComplexDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ComplexDialog);

        QMetaObject::connectSlotsByName(ComplexDialog);
    } // setupUi

    void retranslateUi(QDialog *ComplexDialog)
    {
        ComplexDialog->setWindowTitle(QApplication::translate("ComplexDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ComplexDialog", "Save Changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ComplexDialog: public Ui_ComplexDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPLEXDIALOG_H
