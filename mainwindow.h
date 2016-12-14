#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scientist.h"
#include "service.h"
//#include "addscientistwindow.h"
#include "computer.h"

#include <QMainWindow>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:




public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:
    void on_row_clicked();
    void on_search_box_textChanged();
    void on_pushButton_clicked();
    void on_button_add_scientist_clicked();

    void on_button_scientist_info_clicked();

    void on_dropdown_what_to_look_at_currentTextChanged(const QString &arg1);

    void on_search_box_computer_textChanged();

    void on_button_add_computer_clicked();

    void on_button_info_computer_clicked();

    void on_scientist_table_doubleClicked(const QModelIndex &index);

private:
    void refreshTables();
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    void displayAllComputers();
    void displayComputers(vector<Computer>);

    Ui::MainWindow *ui;
    Service _service;
};

#endif // MAINWINDOW_H
