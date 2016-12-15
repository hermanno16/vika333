#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include "service.h"
#include "computer.h"
#include "dataaccess.h"

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

void addComputerDialog::on_add_Photo_computer_Button_clicked()
{
    string filePath = QFileDialog::getOpenFileName(
                    this,
                    "Search for images",
                    "",
                    "Image files (*.png *.jpg)"
                    ).toStdString();
        if (filePath.length())
        {
            //user selected some file
            QPixmap pixmap(QString::fromStdString(filePath));

            ui->label_computer_photo->setPixmap(pixmap);
            ui->label_computer_photo->setScaledContents(true);

            QFile computerPhoto(QString::fromStdString(filePath));
            if (!computerPhoto.open(QIODevice::ReadOnly)) return;
            QByteArray computerPhotoArray = computerPhoto.readAll();

        }
        else
        {
            //user did not select a file
        }
}

void addComputerDialog::on_pushButton_add_computer_clicked()
{
    Computer newComputer;

    newComputer.setName((ui->computer_Input_Name->text()).toStdString());
    newComputer.setYearBuilt((ui->computer_Input_Year_Built->text()).toInt());
    string development;
    if(ui->radioButton_if_developed->isChecked())
    {
        development = "Developed";
    }
    else
    {
        development = "Original";
    }
    newComputer.setDevelopment(development);
    newComputer.setType((ui->computer_Input_Type->text()).toStdString());
    newComputer.setComputerInfo((ui->computer_Add_Info->text()).toStdString());


    if(!_service.isAddComputerNameValid(newComputer))
    {
        QMessageBox::critical (this, "Error", "Name is not valid!");
        return;
    }
    else if(!_service.isAddComputerYearBuiltValid(newComputer))
    {
        QMessageBox::critical (this, "Error", "Year built is not valid!");
        return;
    }

    _service.fixAddComputerType(newComputer);

    if(!_service.isAddComputerTypeValid(newComputer))
    {
        QMessageBox::critical (this, "Error", "Type of computer is not valid!");
        return;
    }

        QMessageBox::critical (this, "Computer was added!", "Computer was added!");
        _service.addComputerToData(newComputer);
        this->close();
}

