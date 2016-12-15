#include "computereditdialog.h"
#include "ui_computereditdialog.h"
#include "computer.h"


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

void ComputerEditDialog::setIDofCurrentComputer(int id)
{
    _idOfCurrentComputer = id;
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

    ui->computer_edit_Info->setText(QString::fromStdString(computerInfo));
}





void ComputerEditDialog::on_pushButton_save_computer_clicked()
{
    Computer updatedComputer;

    updatedComputer.setName((ui->computer_edit_Name->text()).toStdString());
    updatedComputer.setType((ui->computer_edit_Input_Type->text()).toStdString());
    updatedComputer.setYearBuilt((ui->computer_edit_Year_Built->text()).toInt());
    string development;

    if(ui->radioButton_edit_if_developed->isChecked())
    {
        development = "Developed";
    }
    else
    {
        development = "Original";
    }

    updatedComputer.setDevelopment(development);
    updatedComputer.setComputerInfo((ui->computer_edit_Info->text()).toStdString());
    updatedComputer.setId(_idOfCurrentComputer);

    _service.updateComputerInDataBase(updatedComputer);



    this->close();


}

void ComputerEditDialog::on_cancel_button_clicked()
{
    this->close();
}
