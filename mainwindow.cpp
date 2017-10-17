#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add_tr()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_tr()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(save_tr()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(load_tr()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(del_tr()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(closest()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closest()
{
    tree.closest(ui->lineEdit_11->text().toFloat()).show();
}

void MainWindow::add_tr()
{
    EnergeticVolume *a = new EnergeticVolume(ui->lineEdit->text(),
                                        ui->lineEdit_2->text(),
                                        ui->lineEdit_3->text(),
                                        ui->lineEdit_4->text(),
                                        ui->lineEdit_5->text(),
                                        ui->lineEdit_6->text(),
                                        ui->lineEdit_7->text());
    tree.keyInsert(ui->lineEdit_8->text().toInt(), *a);
}

void MainWindow::show_tr()
{
    tree.show();
}

void MainWindow::save_tr()
{
    tree.save(ui->lineEdit_9->text());
}

void MainWindow::load_tr()
{
    tree.load(ui->lineEdit_9->text());
}

void MainWindow::del_tr()
{
    tree.keyDelete(ui->lineEdit_10->text().toInt());
}
