#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"


using namespace std;

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}




void addComputerDialog::on_pushButton_add_computer_clicked()
{
    QString computerName = ui->computer_Input_Name->text();
    QString computerYearBuilt = ui->computer_Input_Year_Built->text();
    QString computerDevelopment = ui->computer_Input_Development->text();
    QString computerInfo = ui->computer_Add_Info->text();
    QString computerType = ui->computer_Input_Type->text();

    if (computerName.isEmpty())
    {
        QMessageBox::critical (this, "Error", "The Name Cannot Be Empty");
        return;
    }
    else if (computerYearBuilt.isEmpty())
    {
        QMessageBox::critical (this, "Error", "The Building Year Cannot Be Empty");
        return;
    }
    else if (computerDevelopment.isEmpty())
    {
        QMessageBox::critical (this, "Error", "The Development Cannot Be Empty");
        return;
    }
    else if (computerType.isEmpty())
    {
        QMessageBox::critical (this, "Error", "The Type Cannot Be Empty");
        return;
    }
    else
    {
        //ath hvort tölvan er til í gagnagrunninum ef ekki adda upplýsingunum
        return;
    }
}
