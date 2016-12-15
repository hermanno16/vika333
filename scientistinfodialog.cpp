#include "scientistinfodialog.h"
#include "ui_scientistinfodialog.h"
#include "service.h"
#include <QFileDialog>

ScientistInfoDialog::ScientistInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistInfoDialog)
{
    ui->setupUi(this);
}

ScientistInfoDialog::~ScientistInfoDialog()
{
    delete ui;
}

void ScientistInfoDialog::displayInfo(string name,
                                      string gender,
                                      int yearOfBirth,
                                      string yearOfDeath,
                                      string scientistInfo)
{
    ui->info_display_name->setText(QString::fromStdString(name));
    ui->info_display_gender->setText(QString::fromStdString(gender));
    ui->info_display_year_of_birth->setText(QString::number(yearOfBirth));
    ui->info_display_year_of_death->setText(QString::fromStdString(yearOfDeath));

    ui->info_scientist_info->insertPlainText(QString::fromStdString(scientistInfo));
}

void ScientistInfoDialog::relatedComputers(int id)
{
    vector<Computer> relation = _service.connectScientistToComputer(id);
    ui->info_related_computers->clearContents();
    ui->info_related_computers->setRowCount(relation.size());
    ui->info_related_computers->setColumnCount(1);

    for(unsigned int i = 0; i < relation.size(); i++)
    {
        QString name = QString::fromStdString(relation[i].getName());
        ui->info_related_computers->setItem(i, 0, new QTableWidgetItem(name));
    }
}
