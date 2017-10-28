#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addToTree()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showTree()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(saveTree()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(loadTree()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(deleteByKey()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(closestByVolume()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closestByVolume()
{
    tree.closestByVolume(ui->lineEdit_11->text().toFloat()).show();
}

void MainWindow::addToTree()
{
    EnergeticVolume *a = new EnergeticVolume(ui->lineEdit->text(),
                                        ui->lineEdit_2->text(),
                                        ui->lineEdit_3->text(),
                                        ui->lineEdit_4->text(),
                                        ui->lineEdit_5->text(),
                                        ui->lineEdit_6->text(),
                                        ui->lineEdit_7->text());
    tree.keyInsert(*a);
}

void MainWindow::showTree()
{
    tree.show();
}

void MainWindow::saveTree()
{
    tree.save(ui->lineEdit_9->text());
}

void MainWindow::loadTree()
{
    tree.load(ui->lineEdit_9->text());
}

void MainWindow::deleteByKey()
{
    tree.keyDelete(ui->lineEdit_10->text().toFloat());
}
