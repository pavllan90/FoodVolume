#ifndef COMPLEXDIALOG_H
#define COMPLEXDIALOG_H

#include <QDialog>
#include "complex.h"

namespace Ui {
class ComplexDialog;
}

class ComplexDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ComplexDialog(QWidget *parent = 0);
    ~ComplexDialog();
    ComplexDialog(Volume* _shown);
    Complex *shown;
private:
    Ui::ComplexDialog *ui;
private slots:
    void save();
signals:
    void changed();
};

#endif // COMPLEXDIALOG_H
