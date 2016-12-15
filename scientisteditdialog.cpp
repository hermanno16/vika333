#include "scientisteditdialog.h"
#include "ui_scientisteditdialog.h"
#include "scientist.h"
#include <QMessageBox>



scientistEditDialog::scientistEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistEditDialog)
{
    ui->setupUi(this);
}

scientistEditDialog::~scientistEditDialog()
{
    delete ui;
}

void scientistEditDialog::displayInfo(string name, string gender, int yearOfBirth, string yearOfDeath, string scientistInfo)
{

    ui->edit_scientist_name->setText(QString::fromStdString(name));


    if(gender == "Male")
    {
        ui->radioButton_edit_if_male->setChecked(true);

    }
    else if(gender == "Female")
    {
        ui->radioButton_edit_if_female->setChecked(true);
    }

    ui->edit_scientist_year_of_birth->setText(QString::number(yearOfBirth));
    ui->edit_scientist_year_of_death->setText(QString::fromStdString(yearOfDeath));
    ui->edit_text->setText(QString::fromStdString(scientistInfo));
}

void scientistEditDialog::setIDofCurrentScientist(int id)
{
    _idOfCurrentScientist = id;
}

void scientistEditDialog::on_pushButton_save_update_scientist_clicked()
{
    Scientist updatedScientist;

    updatedScientist.setName((ui->edit_scientist_name->text()).toStdString());
    updatedScientist.setYearOfBirth((ui->edit_scientist_year_of_birth->text()).toInt());
    updatedScientist.setYearOfDeath((ui->edit_scientist_year_of_death->text()).toStdString());
    updatedScientist.setScientistInfo((ui->edit_text->text().toStdString()));
    string gender;

    if(ui->radioButton_edit_if_male->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }
    updatedScientist.setID(_idOfCurrentScientist);
    updatedScientist.setGender(gender);

    if((updatedScientist.getName()).length() == 0)
    {
        QMessageBox::critical (this, "Error", "the name cannot be empty!");
        return;
    }

    else if((updatedScientist.getYearOfBirth()) == 0)
    {
        QMessageBox::critical(this, "Error", "the year of birth cannot be empty!");
        return;
    }

    else if(updatedScientist.getYearOfDeath().length() == 0)
    {
        QMessageBox::critical(this, "Error", "the year of death cannot be empty!");
        return;
    }

    _service.fixInputYearOfDeath(updatedScientist);

    if(!_service.isYearOfBirthOfScientistValid(updatedScientist))
    {
        QMessageBox::critical(this, "Error", "the year of birth is not valid!");
        return;
    }

    _service.fixInputNameScientist(updatedScientist);



    _service.updateScientistInDataBase(updatedScientist);

    this->close();
}


void scientistEditDialog::on_cancel_edit_window_clicked()
{
    this->close();
}
