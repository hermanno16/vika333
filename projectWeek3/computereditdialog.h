#ifndef COMPUTEREDITDIALOG_H
#define COMPUTEREDITDIALOG_H
#include <string>
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
private:

    Ui::ComputerEditDialog *ui;
};

#endif // COMPUTEREDITDIALOG_H
