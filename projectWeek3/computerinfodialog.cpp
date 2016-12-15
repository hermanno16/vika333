#include "computerinfodialog.h"
#include "ui_computerinfodialog.h"

ComputerInfoDialog::ComputerInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerInfoDialog)
{
    ui->setupUi(this);
}

ComputerInfoDialog::~ComputerInfoDialog()
{
    delete ui;
}

void ComputerInfoDialog::displayInfo(string name, string type, int yearBuilt, string development, string computerInfo)
{
    ui->computer_display_Name->setText(QString::fromStdString(name));
    ui->computer_display_Year_Built->setText(QString::number(yearBuilt));
    ui->computer_display_Type->setText(QString::fromStdString(type));
    if(development == "Developed")
    {
        ui->radioButton_display_if_developed->setChecked(true);

    }
    else if(development == "Original")
    {
        ui->radioButton_display_if_original->setChecked(true);
    }

    ui->computer_display_Info->setText(QString::fromStdString(computerInfo));



}
