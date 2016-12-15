#include "scientisteditdialog.h"
#include "ui_scientisteditdialog.h"



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

void scientistEditDialog::displayInfo(string name, string gender, int yearOfBirth, string yearOfDeath)
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
}

void scientistEditDialog::on_pushButton_edit_scientist_clicked()
{

}
