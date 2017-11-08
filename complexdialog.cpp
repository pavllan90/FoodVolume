#include "complexdialog.h"
#include "ui_complexdialog.h"

ComplexDialog::ComplexDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComplexDialog)
{
    ui->setupUi(this);
}

ComplexDialog::ComplexDialog(Volume *_shown) :
    ui(new Ui::ComplexDialog), shown(dynamic_cast<Complex*>(_shown))
{
    ui->setupUi(this);
    if(!shown->hasDessert)
        ui->tableWidget->setColumnCount(3);
    else
        ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("First"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Second"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Drink"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Dessert"));
    ui->tableWidget->setVerticalHeaderItem(0, new QTableWidgetItem ("Name: "));
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(shown->dish1.getName()));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem(shown->dish2.getName()));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem(shown->dish3.getName()));
    if(shown->hasDessert) ui->tableWidget->setItem(0,3, new QTableWidgetItem(shown->dish4.getName()));
    ui->tableWidget->setVerticalHeaderItem(1, new QTableWidgetItem ("Weight: "));
    ui->tableWidget->setItem(1,0, new QTableWidgetItem(QString::number(shown->dish1.getWeight())));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem(QString::number(shown->dish2.getWeight())));
    ui->tableWidget->setItem(1,2, new QTableWidgetItem(QString::number(shown->dish3.getWeight())));
    if(shown->hasDessert) ui->tableWidget->setItem(1,3, new QTableWidgetItem(QString::number(shown->dish4.getWeight())));
    ui->tableWidget->setVerticalHeaderItem(2, new QTableWidgetItem ("Fat: "));
    ui->tableWidget->setItem(2,0, new QTableWidgetItem(QString::number(shown->dish1.getFat())));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem(QString::number(shown->dish2.getFat())));
    ui->tableWidget->setItem(2,2, new QTableWidgetItem(QString::number(shown->dish3.getFat())));
    if(shown->hasDessert)ui->tableWidget->setItem(2,3, new QTableWidgetItem(QString::number(shown->dish4.getFat())));
    ui->tableWidget->setVerticalHeaderItem(3, new QTableWidgetItem ("Proteines: "));
    ui->tableWidget->setItem(3,0, new QTableWidgetItem(QString::number(shown->dish1.getProteins())));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem(QString::number(shown->dish2.getProteins())));
    ui->tableWidget->setItem(3,2, new QTableWidgetItem(QString::number(shown->dish3.getProteins())));
    if(shown->hasDessert)  ui->tableWidget->setItem(3,3, new QTableWidgetItem(QString::number(shown->dish4.getProteins())));
    ui->tableWidget->setVerticalHeaderItem(4, new QTableWidgetItem ("Carbonhydrates: "));
    ui->tableWidget->setItem(4,0, new QTableWidgetItem(QString::number(shown->dish1.getCarbonhydrates())));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem(QString::number(shown->dish2.getCarbonhydrates())));
    ui->tableWidget->setItem(4,2, new QTableWidgetItem(QString::number(shown->dish3.getCarbonhydrates())));
    if(shown->hasDessert)   ui->tableWidget->setItem(4,3, new QTableWidgetItem(QString::number(shown->dish4.getCarbonhydrates())));
    ui->tableWidget->setVerticalHeaderItem(5, new QTableWidgetItem ("Acids: "));
    ui->tableWidget->setItem(5,0, new QTableWidgetItem(QString::number(shown->dish1.getAcids())));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem(QString::number(shown->dish2.getAcids())));
    ui->tableWidget->setItem(5,2, new QTableWidgetItem(QString::number(shown->dish3.getAcids())));
    if(shown->hasDessert)ui->tableWidget->setItem(5,3, new QTableWidgetItem(QString::number(shown->dish4.getAcids())));
    ui->tableWidget->setVerticalHeaderItem(6, new QTableWidgetItem ("Food fibers: "));
    ui->tableWidget->setItem(6,0, new QTableWidgetItem(QString::number(shown->dish1.getFfibers())));
    ui->tableWidget->setItem(6,1, new QTableWidgetItem(QString::number(shown->dish2.getFfibers())));
    ui->tableWidget->setItem(6,2, new QTableWidgetItem(QString::number(shown->dish3.getFfibers())));
    if(shown->hasDessert)ui->tableWidget->setItem(6,3, new QTableWidgetItem(QString::number(shown->dish4.getFfibers())));
    ui->tableWidget->setVerticalHeaderItem(7, new QTableWidgetItem ("Volume: "));
    ui->tableWidget->setItem(7,0, new QTableWidgetItem(QString::number(shown->dish1.countVolume())));
    ui->tableWidget->setItem(7,1, new QTableWidgetItem(QString::number(shown->dish2.countVolume())));
    ui->tableWidget->setItem(7,2, new QTableWidgetItem(QString::number(shown->dish3.countVolume())));
    if(shown->hasDessert)ui->tableWidget->setItem(7,3, new QTableWidgetItem(QString::number(shown->dish4.countVolume())));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(save()));
}

ComplexDialog::~ComplexDialog()
{
    delete ui;
}

void ComplexDialog::save()
{
    shown->dish1.setName(ui->tableWidget->item(0,0)->text());
   // shown->dish1.setParameters(ui->tableWidget->item(1,0)->text(), ui->tableWidget->item(2,0)->text(),ui->tableWidget->item(3,0)->text(), ui->tableWidget->item(4,0)->text(),ui->tableWidget->item(5,0)->text(),ui->tableWidget->item(6,0)->text());
    shown->dish1.setName(ui->tableWidget->item(0,1)->text());
   // shown->dish1.setParameters(ui->tableWidget->item(1,1)->text(), ui->tableWidget->item(2,1)->text(),ui->tableWidget->item(3,1)->text(), ui->tableWidget->item(4,1)->text(),ui->tableWidget->item(5,1)->text(),ui->tableWidget->item(6,1)->text());
    shown->dish1.setName(ui->tableWidget->item(0,2)->text());
    //shown->dish1.setParameters(ui->tableWidget->item(1,2)->text(), ui->tableWidget->item(2,2)->text(),ui->tableWidget->item(3,2)->text(), ui->tableWidget->item(4,2)->text(),ui->tableWidget->item(5,2)->text(),ui->tableWidget->item(6,2)->text());
    if(!shown->hasDessert)shown->dish1.setName(ui->tableWidget->item(0,3)->text());
    //shown->dish1.setParameters(ui->tableWidget->item(1,3)->text(), ui->tableWidget->item(2,3)->text(),ui->tableWidget->item(3,3)->text(), ui->tableWidget->item(4,3)->text(),ui->tableWidget->item(5,3)->text(),ui->tableWidget->item(6,3)->text());
    this->close();
    emit changed();
}
