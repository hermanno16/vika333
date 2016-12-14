#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <iostream>
#include <string>
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QRegularExpression>


using namespace std;
namespace Ui {

class addComputerDialog;
}

class addComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerDialog(QWidget *parent = 0);
    ~addComputerDialog();
    string Computer_Name_InputBox;



private slots:
    void on_computer_Submit_Button_clicked();


private:
    Ui::addComputerDialog *ui;
};

#endif // ADDCOMPUTERDIALOG_H
