#ifndef COMPUTERDIALOG_H
#define COMPUTERDIALOG_H
#include "service.h"
#include "computer.h"
//#include "addcomputerwindow.h"

#include <QDialog>

namespace Ui {
class ComputerDialog;
}

class ComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerDialog(QWidget *parent = 0);
    ~ComputerDialog();

private slots:

    void on_row_clicked();

    void on_search_box_textChanged();

    void on_pushButton_clicked();

    void on_button_add_computer_clicked();

    void on_button_computer_info_clicked();

    void on_dropdown_what_to_look_at_currentTextChanged(const QString &arg1);

private:

    void displayAllComputers();
    void displayComputers(vector<Computer>);

    Ui::ComputerDialog *ui;
    Service _service;

};

#endif // COMPUTERDIALOG_H
