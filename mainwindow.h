#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "energeticvolume.h"

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
    EnergeticVolume *mass[10];
    int counter;

private slots:
    void add();
    void showMass();

};

#endif // MAINWINDOW_H
