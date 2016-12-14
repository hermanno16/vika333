#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>
#include "addscientistdialog.h"
#include "scientistinfodialog.h"
#include "addcomputerdialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> scientists = _service.getAllScientistsAtoZ();
    displayScientists(scientists);

}

void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->scientist_table->clearContents();
    ui->scientist_table->setRowCount(scientists.size());
    ui->scientist_table->setColumnHidden(0, true);
    ui->scientist_table->setColumnCount(5);
    ui->scientist_table->setColumnWidth(1, this->width()/3);
    ui->scientist_table->setColumnWidth(2, this->width()/6);
    ui->scientist_table->setColumnWidth(3, this->width()/6);
    ui->scientist_table->setColumnWidth(4, this->width()/6);

    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists[row];

        QString id = QString::number(currentScientist.getID());
        QString name = QString::fromStdString(currentScientist.getName());
        QString gender = QString::fromStdString(currentScientist.getGender());
        QString yearofbirth = QString::number(currentScientist.getYearOfBirth());
        QString yearofdeath = QString::fromStdString(currentScientist.getYearOfDeath());

        ui->scientist_table->setItem(row, 0, new QTableWidgetItem(id));
        ui->scientist_table->setItem(row, 1, new QTableWidgetItem(name));
        ui->scientist_table->setItem(row, 2, new QTableWidgetItem(gender));
        ui->scientist_table->setItem(row, 3, new QTableWidgetItem(yearofbirth));
        ui->scientist_table->setItem(row, 4, new QTableWidgetItem(yearofdeath));
    }
}
void MainWindow::on_row_clicked()
{
    //TODO -- klikka á nafn á listanum, fá upp infoið
}
void MainWindow::on_search_box_textChanged()
{
    string userInput = ui->search_box->text().toStdString();

    vector<Scientist> scientists = _service.searchForScientists(userInput);
    displayScientists(scientists);
}

void MainWindow::on_pushButton_clicked()
{
    /*
    AddScientistDialog addStudentDialog;
    addStudentDialog.exec();
    */
}

void MainWindow::on_button_add_scientist_clicked()
{
   AddScientistDialog addScientistDialog;

   addScientistDialog.exec();
}
void MainWindow::on_button_scientist_info_clicked()
{
    ScientistInfoDialog scientistInfoDialog;

    scientistInfoDialog.exec();
}
void MainWindow::displayAllComputers()
{
    vector<Computer> computers = _service.getAllComputersAtoZ();
    displayComputers(computers);
}
void MainWindow::displayComputers(vector<Computer> computers)
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
void MainWindow::on_dropdown_what_to_look_at_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_search_box_computer_textChanged(const QString &arg1)
{
    string userInput = ui->search_box_computer->text().toStdString();

    vector<Computer> computers = _service.searchForComputers(userInput);
    displayComputers(computers);
}

void MainWindow::on_button_add_computer_clicked()
{
    addComputerDialog AddComputerDialog;
    int addComputerReturnValue = AddComputerDialog.exec();
}

void MainWindow::on_button_info_computer_clicked()
{
   addComputerDialog computerInfoDialog;

   int computerInfoReturnValue = computerInfoDialog.exec();
}
