#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "service.h"
#include "dataaccess.h"
#include "scientist.h"
#include <QMessageBox>
#include <QFileDialog>

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}


void AddScientistDialog::clearAddScientist()
{
    ui->input_scientist_name->setText("");
    ui->input_scientist_year_of_birth->setText("");
    ui->input_scientist_year_of_death->setText("");
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_pushButton_add_scientist_clicked()
{

    Scientist newScientist;

    newScientist.setName((ui->input_scientist_name->text()).toStdString());
    newScientist.setYearOfBirth((ui->input_scientist_year_of_birth->text()).toInt());
    newScientist.setYearOfDeath((ui->input_scientist_year_of_death->text()).toStdString());
    string gender;

    if(ui->radioButton_if_male->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    newScientist.setGender(gender);

    if((newScientist.getName()).length() == 0)
    {
        QMessageBox::critical (this, "Error", "the name cannot be empty!");
        return;
    }

    else if((newScientist.getYearOfBirth()) == 0)
    {
        QMessageBox::critical(this, "Error", "the year of birth cannot be empty!");
        return;
    }

    _service.fixInputYearOfDeath(newScientist);

    if(!_service.isYearOfBirthOfScientistValid(newScientist))
    {
        QMessageBox::critical(this, "Error", "the year of birth is not valid!");
        return;
    }

    _service.fixInputNameScientist(newScientist);

    if(_service.isScientistAlreadyInDatabase(newScientist))
    {
        QMessageBox::critical(this, "Error", "the scientist is already in database!");
        return;
    }
    else if(newScientist.getYearOfDeath().length() == 0)
    {
        QMessageBox::critical(this, "Error", "the year of death cannot be empty!");
        return;
    }

     _service.addScientistToData(newScientist);

     QMessageBox::Accepted;
    //If scientist was added. Window will close.
    this->close();
}

void AddScientistDialog::on_cancel_add_scientist_window_clicked()
{
    this->close();
}
