#include "addrelation.h"
#include "ui_addrelation.h"
#include <string>
#include "service.h"

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

    bool success = _service.addRelation(scientistName, computerName);

    if(success)
    {
    this->close();
    }
}
