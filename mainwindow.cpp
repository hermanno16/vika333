#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>
#include "computereditdialog.h"
#include "computerinfodialog.h"
#include "addscientistdialog.h"
#include "scientistinfodialog.h"
#include "addcomputerdialog.h"
#include "scientisteditdialog.h"
#include "addrelation.h"
#include <QModelIndex>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    refreshTable();
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
void MainWindow::refreshTable()
{
    displayAllScientists();
    displayAllComputers();
    ui->button_scientist_remove->setEnabled(false);
    ui->button_scientist_info->setEnabled(false);
    ui->button_scientist_edit->setEnabled(false);
    ui->button_computer_edit->setEnabled(false);
    ui->button_computer_remove->setEnabled(false);
    ui->button_info_computer->setEnabled(false);
}
void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->scientist_table->setSortingEnabled(false);

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

    currentlyDisplayedScientists = scientists;
    ui->scientist_table->setSortingEnabled(true);
}
void MainWindow::on_search_box_textChanged()
{
    string userInput = ui->search_box->text().toStdString();

    vector<Scientist> scientists = _service.searchForScientists(userInput);
    refreshTable();
    displayScientists(scientists);

}
void MainWindow::on_button_add_scientist_clicked()
{
   AddScientistDialog addScientistDialog;

   addScientistDialog.exec();
   refreshTable();
}
void MainWindow::displayAllComputers()
{
    vector<Computer> computers = _service.getAllComputersAtoZ();
    displayComputers(computers);
}
void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->computer_table->setSortingEnabled(false);

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

    currentlyDisplayedComputers = computers;
    ui->computer_table->setSortingEnabled(true);

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
    refreshTable();
}
int MainWindow::getComputerID() const
{
    int row = ui->computer_table->currentRow();

    if (row != -1)
    {
        return ui->computer_table->item(row,0)->text().toInt();
    }

    return -1;
}
void MainWindow::on_button_info_computer_clicked()
{  
    int computerID = getComputerID();

    Computer currentlySelectedComputer = _service.searchForComputerID(computerID);

    ComputerInfoDialog computerInfoDialog;

    computerInfoDialog.relatedScientists(computerID);

    computerInfoDialog.displayInfo(currentlySelectedComputer.getName(),
                                   currentlySelectedComputer.getType(),
                                   currentlySelectedComputer.getYearBuilt(),
                                   currentlySelectedComputer.getDevelopment(),
                                   currentlySelectedComputer.getComputerInfo());

    computerInfoDialog.exec();

    refreshTable();


}
void MainWindow::on_button_scientist_remove_clicked()
{
    int currentlySelectedScientistIndex = ui->scientist_table->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    if(answer == QMessageBox::No)
    {
        return;
    }
    else
    {
        _service.removeScientistFromDataBase(currentlySelectedScientist.getID());
    }

    refreshTable();
}
int MainWindow::getScientistID() const
{
    int row = ui->scientist_table->currentRow();

    if (row != -1)
    {
        return ui->scientist_table->item(row,0)->text().toInt();
    }

    return -1;
}
void MainWindow::on_button_scientist_info_clicked()
{
    int scientistID = getScientistID();

    Scientist currentlySelectedScientist = _service.searchForScientistID(scientistID);

    ScientistInfoDialog scientistInfoDialog;

    scientistInfoDialog.relatedComputers(scientistID);

    scientistInfoDialog.displayInfo(currentlySelectedScientist.getName(),
                                    currentlySelectedScientist.getGender(),
                                    currentlySelectedScientist.getYearOfBirth(),
                                    currentlySelectedScientist.getYearOfDeath(),
                                    currentlySelectedScientist.getScientistInfo());

    scientistInfoDialog.exec();

    refreshTable();
}
void MainWindow::on_scientist_table_clicked(const QModelIndex &index)
{
    ui->button_scientist_remove->setEnabled(true);
    ui->button_scientist_info->setEnabled(true);
    ui->button_scientist_edit->setEnabled(true);
}
void MainWindow::on_button_scientist_edit_clicked()
{
    int currentlySelectedScientistIndex = ui->scientist_table->currentIndex().row();
    Scientist currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);
    int idOfSelectedScientist = currentlySelectedScientist.getID();



    scientistEditDialog scientisteditDialog;
    scientisteditDialog.setIDofCurrentScientist(idOfSelectedScientist);
    scientisteditDialog.displayInfo(currentlySelectedScientist.getName(),
                                    currentlySelectedScientist.getGender(),
                                    currentlySelectedScientist.getYearOfBirth(),
                                    currentlySelectedScientist.getYearOfDeath(),
                                    currentlySelectedScientist.getScientistInfo());

    scientisteditDialog.exec();
    refreshTable();
}

void MainWindow::on_add_relation_clicked()
{
    AddRelation addRelation;

    addRelation.exec();
}
void MainWindow::on_add_relation_2_clicked()
{
    AddRelation addRelation;

    addRelation.exec();
}

void MainWindow::on_button_computer_remove_clicked()
{
    int currentlySelectedComputerIndex = ui->computer_table->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    if(answer == QMessageBox::No)
    {
        return;
    }
    else
    {
         _service.removeComputerFromDataBase(currentlySelectedComputer.getId());
    }

    refreshTable();
}
void MainWindow::on_computer_table_clicked(const QModelIndex &index)
{
    ui->button_computer_edit->setEnabled(true);
    ui->button_computer_remove->setEnabled(true);
    ui->button_info_computer->setEnabled(true);
}
void MainWindow::on_button_computer_edit_clicked()
{
    int currentlySelectedComputerIndex = ui->computer_table->currentIndex().row();
    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);
    int idOfSelectedComputer = currentlySelectedComputer.getId();

    ComputerEditDialog computerEditDialog;
    computerEditDialog.setIDofCurrentComputer(idOfSelectedComputer);
    computerEditDialog.displayInfo(currentlySelectedComputer.getName(),
                                   currentlySelectedComputer.getType(),
                                   currentlySelectedComputer.getYearBuilt(),
                                   currentlySelectedComputer.getDevelopment(),
                                   currentlySelectedComputer.getComputerInfo());


    computerEditDialog.exec();
    refreshTable();
}

