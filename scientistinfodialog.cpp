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
/*
void ScientistInfoDialog::on_id_input_textChanged()
{
    int userInput = ui->id_input->text();

    vector<Scientist> scientists = _service.searchForScientists()
}
*/
/*
void ScientistInfoDialog::displayScientistData(vector<Scientist> input[i])
{
    ui->scientist_data->clearContents();
    ui->scientist_data->setRowCount(1);
    ui->scientist_data->setColumnCount(5);
    ui->scientist_data->setColumnWidth(1, this->width()/3);
    ui->scientist_data->setColumnWidth(2, this->width()/6);
    ui->scientist_data->setColumnWidth(3, this->width()/6);
    ui->scientist_data->setColumnWidth(4, this->width()/6);

    Scientist currentScientist = input[i};

    QString id = QString::number(input.getID());
    QString name = QString::fromStdString(input.getName());
    QString gender = QString::fromStdString(input.getGender());
    QString yearofbirth = QString::number(input.getYearOfBirth());
    QString yearofdeath = QString::fromStdString(input.getYearOfDeath());

    ui->scientist_data->setItem(row, 0, new QTableWidgetItem(id));
    ui->scientist_data->setItem(row, 1, new QTableWidgetItem(name));
    ui->scientist_data->setItem(row, 2, new QTableWidgetItem(gender));
    ui->scientist_data->setItem(row, 3, new QTableWidgetItem(yearofbirth));
    ui->scientist_data->setItem(row, 4, new QTableWidgetItem(yearofdeath));
}*/

/*
void ScientistInfoDialog::on_button_browse_image_clicked() //Tekur örugglega inn eitthvað
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                "Serch for imegis",
                "",
                "Image files (*.png *.jpg)"
                );
    if (filePath.length())
    {
        QPixmap scientistPhoto(filePath);

        ui->label_image->setPixmap(scientistPhoto);
    }
    else
    {
        //user did not select a file
    }
}
*/

/*void ScientistInfoDialog::on_button_edit_scientist_clicked()
{
    _service.getAllScientistsAtoZ();
}
void ScientistInfoDialog::on_button_delete_scientist_clicked()
{
    // Kalla á remove fallið
}*/
