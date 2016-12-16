#include "addrelation.h"
#include "ui_addrelation.h"
#include <string>
#include "service.h"
#include <QMessageBox>

using namespace std;

AddRelation::AddRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelation)
{
    ui->setupUi(this);
}

AddRelation::~AddRelation()
{
    delete ui;
}
void AddRelation::on_ok_clicked()
{
    string scientistName = ui->scientist_input->toPlainText().toStdString();
    string computerName = ui->computer_input->toPlainText().toStdString();

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    if(answer == QMessageBox::No)
    {
        return;
    }
    else
    {
        bool success = _service.addRelation(scientistName, computerName);

        if(success)
        {
           this->close();
        }
    }
}
