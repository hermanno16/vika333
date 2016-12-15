#include "computerinfodialog.h"
#include "ui_computerinfodialog.h"
#include "service.h"

ComputerInfoDialog::ComputerInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerInfoDialog)
{
    ui->setupUi(this);
}

ComputerInfoDialog::~ComputerInfoDialog()
{
    delete ui;
}

void ComputerInfoDialog::displayInfo(string name,
                                     string type,
                                     int yearBuilt,
                                     string development,
                                     string computerInfo)
{
    ui->computer_display_Name->setText(QString::fromStdString(name));
    ui->computer_display_Year_Built->setText(QString::number(yearBuilt));
    ui->computer_display_Type->setText(QString::fromStdString(type));
    if(development == "Developed")
    {
        ui->radioButton_display_if_developed->setChecked(true);

    }
    else if(development == "Original")
    {
        ui->radioButton_display_if_original->setChecked(true);
    }

    ui->info_computer_info->insertPlainText(QString::fromStdString(computerInfo));
}
void ComputerInfoDialog::relatedScientists(int cid)
{
    vector<Scientist> relation = _service.connectComputerToScientist(cid);
    ui->info_related_scientists->clearContents();
    ui->info_related_scientists->setRowCount(relation.size());
    ui->info_related_scientists->setColumnCount(1);

    for(unsigned int i = 0; i < relation.size(); i++)
    {
        QString name = QString::fromStdString(relation[i].getName());
        ui->info_related_scientists->setItem(i, 0, new QTableWidgetItem(name));
    }
}
