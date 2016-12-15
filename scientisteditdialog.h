#ifndef SCIENTISTEDITDIALOG_H
#define SCIENTISTEDITDIALOG_H
#include "service.h"


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
    void displayInfo(std::string name, string gender, int yearOfBirth, string yearOfDeath, string scientistInfo);
    void setIDofCurrentScientist(int id);


private slots:
    void on_pushButton_save_update_scientist_clicked();
    void on_pushButton_edit_scientist_clicked();

    void on_pushButton_add_scientist_clicked();



    void on_pushButton_2_clicked();

    void on_cancel_edit_window_clicked();

private:
    Ui::scientistEditDialog *ui;
    Service _service;
    int _idOfCurrentScientist;
};

#endif // SCIENTISTEDITDIALOG_H
