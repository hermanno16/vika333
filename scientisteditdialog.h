#ifndef SCIENTISTEDITDIALOG_H
#define SCIENTISTEDITDIALOG_H


#include <QDialog>
//#include <string>
using namespace std;

namespace Ui {
class scientistEditDialog;
}

class scientistEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scientistEditDialog(QWidget *parent = 0);
    ~scientistEditDialog();
    void displayInfo(std::string name, string gender, int yearOfBirth, string yearOfDeath);

private:
    Ui::scientistEditDialog *ui;
};

#endif // SCIENTISTEDITDIALOG_H
