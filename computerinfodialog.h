#ifndef COMPUTERINFODIALOG_H
#define COMPUTERINFODIALOG_H

#include"service.h"
#include <QDialog>

using namespace std;


namespace Ui {
class ComputerInfoDialog;
}

class ComputerInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerInfoDialog(QWidget *parent = 0);
    ~ComputerInfoDialog();
    void displayInfo(string name, string type, int yearBuilt, string development, string computerInfo);
    void relatedScientists(int cid);
private:
    Ui::ComputerInfoDialog *ui;

    Service _service;
};

#endif // COMPUTERINFODIALOG_H
