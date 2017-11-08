#ifndef DISHDIALOG_H
#define DISHDIALOG_H

#include <QDialog>
#include "energeticvolume.h"

namespace Ui {
class DishDialog;
}

class DishDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DishDialog(QWidget *parent = 0);
    DishDialog (Volume *_shown);
    EnergeticVolume *shown;

    ~DishDialog();
    
private:
    Ui::DishDialog *ui;
private slots:
    void save();

signals:
    void changed();
};

#endif // DISHDIALOG_H
