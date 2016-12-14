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

void ScientistInfoDialog::displayInfo(string name, string gender, int yearOfBirth, string yearOfDeath)
{
    ui->info_display_name->setText(QString::fromStdString(name));
    ui->info_display_gender->setText(QString::fromStdString(gender));
    ui->info_display_year_of_birth->setText(QString::number(yearOfBirth));
    ui->info_display_year_of_death->setText(QString::fromStdString(yearOfDeath));
}

