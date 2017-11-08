#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addDishToTree()));
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(showTree(int)));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(saveTree()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(loadTree()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(deleteByKey()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(closestByVolume()));
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(addComplexToTree()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(sizeTree()));
    QObject::connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(isEmpty()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(showOne(QTreeWidgetItem*)));
    mass[0]=NULL;
    mass[1]=NULL;
    mass[2]=NULL;
    mass[3]=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closestByVolume()
{
    Volume * temp = tree.closestByVolume(ui->lineEdit_11->text().toFloat());
    if(temp->getType()==0)
    {
        dial = new DishDialog(temp);
        dial->show();
    }
    else
    {
        c_dial = new ComplexDialog(temp);
        c_dial->show();
    }
}

void MainWindow::showOne(QTreeWidgetItem *_item)
{
    QStringList a = _item->text(0).split(":");
    Volume * temp = tree.closestByVolume(a.at(1).toFloat());
    if(temp->getType()==0)
    {
        dial = new DishDialog(temp);
        dial->show();
    }
    else
    {
        c_dial = new ComplexDialog(temp);
        c_dial->show();
    }
}

void MainWindow::addDishToTree()
{
    EnergeticVolume *a = new EnergeticVolume(ui->lineEdit->text(),
                                        ui->lineEdit_2->text(),
                                        ui->lineEdit_3->text(),
                                        ui->lineEdit_4->text(),
                                        ui->lineEdit_5->text(),
                                        ui->lineEdit_6->text(),
                                        ui->lineEdit_7->text());
    tree.keyInsert(a);
}

void MainWindow::addComplexToTree()
{
    int i =0;
    for(; i<4 && mass[i]; i++);
    if(i<4)
    {
        switch (i)
        {
        case 0:
            ui->label_15->setText("Add second dish: ");
            break;
        case 1:
            ui->label_15->setText("Add drink: ");
            break;
        case 2:
            ui->label_15->setText("Add dessert: ");
        break;
        }

        mass[i] = new EnergeticVolume (ui->lineEdit_8->text(),
                                       ui->lineEdit_12->text(),
                                       ui->lineEdit_13->text(),
                                       ui->lineEdit_14->text(),
                                       ui->lineEdit_15->text(),
                                       ui->lineEdit_16->text(),
                                       ui->lineEdit_17->text());
        ui->lineEdit_8->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_14->clear();
        ui->lineEdit_15->clear();
        ui->lineEdit_16->clear();
        ui->lineEdit_17->clear();
    }
    if(!ui->checkBox->isChecked())
    {
        if(i==3)
        {
            tree.keyInsert(new Complex(*mass[0], *mass[1], *mass[2], *mass[3]));
            mass[0]=mass[1]=mass[2]=mass[3] = NULL;
            tree.show();
            ui->label_15->setText("Add first dish: ");
        }
    }
    else
        if(i==2)
        {
            tree.keyInsert(new Complex(*mass[0], *mass[1], *mass[2]));
            mass[0]=mass[1]=mass[2]=mass[3] = NULL;
            tree.show();
            ui->label_15->setText("Add first dish: ");
        }
}

void MainWindow::sizeTree()
{
    ui->label_17->setText("Size is "+ QString::number(tree.size()));
}

void MainWindow::isEmpty()
{
    if(tree.isEmpty())
        ui->label_17->setText("Empty");
    else
        ui->label_17->setText("Not empty");
}

void MainWindow::showTree(int a)
{
    if(!tree.isEmpty()&&a==2){
        ui->treeWidget->clear();
        QTreeWidgetItem *item = new QTreeWidgetItem(0);
        if(tree.root->data->getType()==0)
            item->setText(0, dynamic_cast<EnergeticVolume*>(tree.root->data)->getName()+" : "+QString::number(dynamic_cast<EnergeticVolume*>(tree.root->data)->countVolume()));
        else
            item->setText(0, "Complex : "+QString::number(dynamic_cast<Complex*>(tree.root->data)->volume));
        ui->treeWidget->addTopLevelItem(item);
        recursiveShow(tree.root, item);
    }
}

void MainWindow::recursiveShow(Node *_root, QTreeWidgetItem *_parent)
{
    if(!_root->isLeaf)
    {
         if(!_root->left->isLeaf)
         {
             QTreeWidgetItem* left = new QTreeWidgetItem(0);
             if(_root->left->data->getType()==0)
                 left->setText(0, dynamic_cast<EnergeticVolume*>(_root->left->data)->getName() +" : "+ QString::number(dynamic_cast<EnergeticVolume*>(_root->left->data)->countVolume()));
             else
                 left->setText(0, "Complex : " +QString::number(dynamic_cast<Complex*>(_root->left->data)->volume));
             _parent->addChild(left);
            recursiveShow(_root->left, left);
         }
         if(!_root->right->isLeaf)
         {
             QTreeWidgetItem* right = new QTreeWidgetItem(0);
             if(_root->right->data->getType()==0)
                right->setText(0, dynamic_cast<EnergeticVolume*>(_root->right->data)->getName()+" : "+QString::number(dynamic_cast<EnergeticVolume*>(_root->right->data)->countVolume()));
             else
                right->setText(0, "Complex : "+QString::number(dynamic_cast<Complex*>(_root->right->data)->volume));
              _parent->addChild(right);
            recursiveShow(_root->right, right);
         }
    }
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
