#ifndef COMPUTERINFODIALOG_H
#define COMPUTERINFODIALOG_H

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

private:
    Ui::ComputerInfoDialog *ui;
};

#endif // COMPUTERINFODIALOG_H
