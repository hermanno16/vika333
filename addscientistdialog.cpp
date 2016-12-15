#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include "service.h"
#include "dataaccess.h"
#include "scientist.h"
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

void AddScientistDialog::on_pushButton_add_scientist_clicked(){

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
     _service.addScientistToData(newScientist);

    //If scientist was added. Window will close.
    this->close();
}

void AddScientistDialog::on_cancel_add_scientist_window_clicked()
{
    this->close();
}

void AddScientistDialog::on_pushButton_3_clicked()
{
    string filePath = QFileDialog::getOpenFileName(
                this,
                "Search for images",
                "",
                "Image files (*.png *.jpg)"
                ).toStdString();
    if (filePath.length())
    {
        QPixmap pixmap(QString::fromStdString(filePath));
        ui->label_scientist_photo->setPixmap(pixmap);
    }
    else
    {

    }
}
