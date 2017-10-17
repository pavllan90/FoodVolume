#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cassert>

int main(int argc, char *argv[])
{
   Tree tree;
   assert(tree.size()==0&&tree.isEmpty());
   tree.keyInsert(43, EnergeticVolume("Pasta", "22.1","23", "10", "10", "5", "5"));
   assert(tree.size()==1&&!tree.isEmpty());
   assert(tree.keySearch(tree.getRoot(), 43)->data.getName()=="Pasta");
   tree.keyInsert(43, EnergeticVolume("Fried potatto",  "22.1","23", "10", "10", "5", "5"));
   assert(tree.size()==1&&tree.keySearch(tree.getRoot(), 43)->data.getName()=="Pasta");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
   return 0;
}
