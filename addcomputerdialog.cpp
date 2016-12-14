#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include <QMessageBox>
#include <iostream>
#include <QLineEdit>
#include <QString>

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


void addComputerDialog::on_computer_Submit_Button_clicked()
{
    //if (Computer_Name_InputBox->text().isEmpty())
    //{
        QMessageBox::about(this, "Error", "No, Name Entered");
    //}
}
