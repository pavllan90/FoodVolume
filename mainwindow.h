#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"
#include <QTreeWidgetItem>
#include "dishdialog.h"
#include "complexdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Tree tree;
    int complex_counter;
    EnergeticVolume* mass[4];
    DishDialog *dial;
    ComplexDialog *c_dial;
private slots:
    void addDishToTree();
    void addComplexToTree();
    void showTree(int a);
    void saveTree();
    void loadTree();
    void sizeTree();
    void isEmpty();
    void deleteByKey();
    void closestByVolume();
    void recursiveShow(Node *_root, QTreeWidgetItem *_parent);
    void showOne(QTreeWidgetItem* _item);

};

#endif // MAINWINDOW_H
