#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H
#include "service.h"

#include <QDialog>
using namespace std;

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:


    void on_pushButton_add_scientist_clicked();

    void on_cancel_add_scientist_window_clicked();

private:
    void clearAddScientist();
    Ui::AddScientistDialog *ui;
    Service _service;
};

#endif // ADDSCIENTISTDIALOG_H
