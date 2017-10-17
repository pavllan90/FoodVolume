#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"

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

private slots:
    void add_tr();
    void show_tr();
    void save_tr();
    void load_tr();
    void del_tr();
    void closest();
};

#endif // MAINWINDOW_H
