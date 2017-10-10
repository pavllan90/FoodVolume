#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter = 0;
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showMass()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add()
{
    mass[counter] = new EnergeticVolume(ui->lineEdit->text(),
                                        ui->lineEdit_2->text(),
                                        ui->lineEdit_3->text(),
                                        ui->lineEdit_4->text(),
                                        ui->lineEdit_5->text(),
                                        ui->lineEdit_6->text(),
                                        ui->lineEdit_7->text());
    counter+=1;
}

void MainWindow::showMass()
{
    ui->textEdit->append("--------------------\n");
    for(int i = 0; i<counter; i++)
        ui->textEdit->append("\nDish #"+QString::number(i+1)+
                             "\nName: "+mass[i]->getName()+
                             "\nWeight: "+QString::number(mass[i]->getWeight())+
                             "\nFat: "+QString::number(mass[i]->getFat())+
                             "\nProteins: "+QString::number(mass[i]->getProteins())+
                             "\nCarbs: "+QString::number(mass[i]->getCarbonhydrates())+
                             "\nAcids: "+QString::number(mass[i]->getAcids())+
                             "\nFibers: "+QString::number(mass[i]->getFfibers())+
                             "\nVolume: "+QString::number(mass[i]->countVolume())+"\n");
}
