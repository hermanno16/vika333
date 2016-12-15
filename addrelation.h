#ifndef ADDRELATION_H
#define ADDRELATION_H
#include <string>
#include "service.h"
#include <QDialog>

namespace Ui {
class AddRelation;
}

class AddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelation(QWidget *parent = 0);
    ~AddRelation();

private slots:
    void on_ok_clicked();

private:
    Ui::AddRelation *ui;
    Service _service;
};

#endif // ADDRELATION_H
