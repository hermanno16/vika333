#include "computereditdialog.h"
#include "ui_computereditdialog.h"


ComputerEditDialog::ComputerEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerEditDialog)
{
    ui->setupUi(this);
}

ComputerEditDialog::~ComputerEditDialog()
{
    delete ui;
}

void ComputerEditDialog::displayInfo(string name, string type, int yearBuilt, string development, string computerInfo)
{
    ui->computer_edit_Name->setText(QString::fromStdString(name));
    ui->computer_edit_Year_Built->setText(QString::number(yearBuilt));
    ui->computer_edit_Input_Type->setText(QString::fromStdString(type));
    if(development == "Developed")
    {
        ui->radioButton_edit_if_developed->setChecked(true);

    }
    else if(development == "Original")
    {
        ui->radioButton_edit_if_original->setChecked(true);
    }

    ui->computer_Add_Info->setText(QString::fromStdString(computerInfo));
}


