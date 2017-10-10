#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    EnergeticVolume x;
    x.show();
    EnergeticVolume y ("Antrecoat", "254.2", "12.5", "23.1", "35.3", "10.01", "19.1");
    y.show();
    EnergeticVolume z = y;
    z.show();
    z.setName("Icecream");
    z.setParameters("4.3", "100.4", "3.1", "3", "34.3", "1");
    z.show();
    z.setParameters("d", "23", "11", "-32", "5", "5");
    z.show();
    z.setParameters("340", "23", "1f1", "32", "5", "5");
    z.show();
    z.setParameters("340", "23", "11", "32", "5", "5");
    z.show();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
