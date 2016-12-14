#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "service.h"
#include "dataaccess.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);

}


//void AddScientistDialog::clearAddScientist



AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_pushButton_add_scientist_clicked()
{
    QString name = ui->input_scientist_name->text();
    QString yearOfBirth = ui->input_scientist_year_of_birth->text();
    QString yearOfDeath = ui->input_scientist_year_of_death->text();
    string gender;
    if(ui->radioButton_if_male->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    /*
    if(name.isEmpty())
    {
        isValid = false;

    }

    if(yearOfBirth.isEmpty())
    {
        isValid = false;
    }


    if(yearOfDeath.isEmpty())
    {
        isValid = false;
    }
    */
    this->close();
     _service.addScientistToData(name.toStdString(), yearOfBirth.toStdString(), yearOfDeath.toStdString(), gender);

}
