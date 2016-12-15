#ifndef COMPUTEREDITDIALOG_H
#define COMPUTEREDITDIALOG_H
#include <string>
#include "service.h"
#include <QDialog>
using namespace std;

namespace Ui {
class ComputerEditDialog;
}

class ComputerEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerEditDialog(QWidget *parent = 0);
    ~ComputerEditDialog();
    void displayInfo(string name, string type, int yearBuilt, string development, string computerInfo);
    void setIDofCurrentComputer(int id);
private slots:
    void on_pushButton_save_computer_clicked();

    void on_cancel_button_clicked();

private:
    int _idOfCurrentComputer;
    Ui::ComputerEditDialog *ui;
    Service _service;

};

#endif // COMPUTEREDITDIALOG_H
