#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scientist.h"
#include <vector>
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_search_box_textChanged();
    void on_button_add_scientist_clicked();
    void on_button_scientist_info_clicked();
    void on_search_box_computer_textChanged(const QString &arg1);
    void on_button_add_computer_clicked();
    void on_button_info_computer_clicked();
    void on_button_scientist_remove_clicked();
    void on_scientist_table_clicked(const QModelIndex &index);
    void on_button_scientist_edit_clicked();
    void on_add_relation_clicked();
    void on_button_computer_remove_clicked();
    void on_computer_table_clicked(const QModelIndex &index);
    void on_button_computer_edit_clicked();

private:
    void refreshTable();
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    void displayAllComputers();
    void displayComputers(vector<Computer> computers);

    Ui::MainWindow *ui;
    Service _service;

    vector<Scientist> currentlyDisplayedScientists;
    vector<Computer> currentlyDisplayedComputers;

};

#endif // MAINWINDOW_H
