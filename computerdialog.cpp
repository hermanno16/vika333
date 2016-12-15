#include "computerdialog.h"
#include "ui_computerdialog.h"
#include <string>
#include <QString>
#include "addcomputerdialog.h"


using namespace std;

ComputerDialog::ComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerDialog)
{
    ui->setupUi(this);

    displayAllComputers();

    ui->dropdown_what_to_look_at->addItem(" Computers");
    ui->dropdown_what_to_look_at->addItem(" Scientists");

}

ComputerDialog::~ComputerDialog()
{
    delete ui;
}

void ComputerDialog::displayAllComputers()
{
    vector<Computer> computers = _service.getAllComputersAtoZ();
    displayComputers(computers);
}
void ComputerDialog::displayComputers(vector<Computer> computers)
{
    ui->computer_table->clearContents();
    ui->computer_table->setRowCount(computers.size());
    ui->computer_table->setColumnHidden(0, true);
    ui->computer_table->setColumnCount(5);
    ui->computer_table->setColumnWidth(1, this->width()/3);
    ui->computer_table->setColumnWidth(2, this->width()/6);
    ui->computer_table->setColumnWidth(3, this->width()/6);
    ui->computer_table->setColumnWidth(4, this->width()/6);

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputer = computers[row];

        QString id = QString::number(currentComputer.getId());
        QString name = QString::fromStdString(currentComputer.getName());
        QString type = QString::fromStdString(currentComputer.getType());
        QString yearbuilt = QString::number(currentComputer.getYearBuilt());
        QString development = QString::fromStdString(currentComputer.getDevelopment());

        ui->computer_table->setItem(row, 0, new QTableWidgetItem(id));
        ui->computer_table->setItem(row, 1, new QTableWidgetItem(name));
        ui->computer_table->setItem(row, 2, new QTableWidgetItem(type));
        ui->computer_table->setItem(row, 3, new QTableWidgetItem(yearbuilt));
        ui->computer_table->setItem(row, 4, new QTableWidgetItem(development));
    }
}
void ComputerDialog::on_row_clicked()
{
    //TODO -- klikka á nafn á listanum, fá upp infoið
}
void ComputerDialog::on_search_box_textChanged()
{
    string userInput = ui->search_box_computer->text().toStdString();

    vector<Computer> computers = _service.searchForComputers(userInput);
    displayComputers(computers);
}
void ComputerDialog::on_pushButton_clicked()
{
    /*
    AddScientistDialog addStudentDialog;
    addStudentDialog.exec();
    */
}
void ComputerDialog::on_button_add_computer_clicked()
{
    addComputerDialog AddComputerDialog;
    int addComputerReturnValue = AddComputerDialog.exec();
}
void ComputerDialog::on_button_computer_info_clicked()
{
  // AddComputerDialog computerInfoDialog;

  //int computerInfoReturnValue = computerInfoDialog.exec();
}
void ComputerDialog::on_dropdown_what_to_look_at_currentTextChanged(const QString &arg1)
{


}

