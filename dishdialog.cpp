#include "dishdialog.h"
#include "ui_dishdialog.h"

DishDialog::DishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishDialog)
{
    ui->setupUi(this);
}

DishDialog::DishDialog(Volume *_shown) : ui(new Ui::DishDialog), shown(dynamic_cast<EnergeticVolume*>(_shown))
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Dish"));
    ui->tableWidget->setVerticalHeaderItem(0, new QTableWidgetItem ("Name: "));
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(shown->getName()));
    ui->tableWidget->setVerticalHeaderItem(1, new QTableWidgetItem ("Weight: "));
    ui->tableWidget->setItem(1,0, new QTableWidgetItem(QString::number(shown->getWeight())));
    ui->tableWidget->setVerticalHeaderItem(2, new QTableWidgetItem ("Fat: "));
    ui->tableWidget->setItem(2,0, new QTableWidgetItem(QString::number(shown->getFat())));
    ui->tableWidget->setVerticalHeaderItem(3, new QTableWidgetItem ("Proteines: "));
    ui->tableWidget->setItem(3,0, new QTableWidgetItem(QString::number(shown->getProteins())));
    ui->tableWidget->setVerticalHeaderItem(4, new QTableWidgetItem ("Carbonhydrates: "));
    ui->tableWidget->setItem(4,0, new QTableWidgetItem(QString::number(shown->getCarbonhydrates())));
    ui->tableWidget->setVerticalHeaderItem(5, new QTableWidgetItem ("Acids: "));
    ui->tableWidget->setItem(5,0, new QTableWidgetItem(QString::number(shown->getAcids())));
    ui->tableWidget->setVerticalHeaderItem(6, new QTableWidgetItem ("Food fibers: "));
    ui->tableWidget->setItem(6,0, new QTableWidgetItem(QString::number(shown->getFfibers())));
    ui->tableWidget->setVerticalHeaderItem(7, new QTableWidgetItem ("Volume: "));
    ui->tableWidget->setItem(7,0, new QTableWidgetItem(QString::number(shown->countVolume())));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(save()));
}



DishDialog::~DishDialog()
{
    delete ui;
}

void DishDialog::save()
{
    shown->setName(ui->tableWidget->item(0,0)->text());
    //shown->setParameters(ui->tableWidget->item(1,0)->text(), ui->tableWidget->item(2,0)->text(),ui->tableWidget->item(3,0)->text(), ui->tableWidget->item(4,0)->text(),ui->tableWidget->item(5,0)->text(),ui->tableWidget->item(6,0)->text());
    emit changed();
}
