#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cassert>

int main(int argc, char *argv[])
{
    Tree tree;
//    assert(tree.size()==0&&tree.isEmpty());
//    tree.keyInsert(EnergeticVolume("Sashlik", "22.1","23", "10", "10", "5", "5"));
//    assert(tree.size()==1&&!tree.isEmpty());
//    assert(tree.keySearch("Sashlik").getName()=="Sashlik");
//    tree.keyInsert(EnergeticVolume("Fr",  "22.1","23", "10", "10", "5", "5"));
//    assert(tree.size()==2&&tree.keySearch("Fr").getName()=="Fr");
//    tree.keyInsert(EnergeticVolume("Pasta", "22.1","23", "10", "10", "5", "5"));
//    Tree copy = tree;
//    assert(tree.size()==copy.size());
//    assert(tree.keySearch("Sashlik").getName()==copy.keySearch("Sashlik").getName());
//    assert(tree.keySearch("Fr").getName()==copy.keySearch("Fr").getName());
//    assert(tree.keySearch("Pasta").getName()==copy.keySearch("Pasta").getName());
//    tree.keyDelete("Pasta");
//    assert(tree.size()!=copy.size());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    //return 0;
}
