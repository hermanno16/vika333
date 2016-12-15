#include "mainwindow.h"
#include "computerdialog.h"
#include "service.h"
#include "dataaccess.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    DataAccess _dAccess;
    _dAccess.openDataBase();
    MainWindow w;


    w.show();



    return a.exec();
}
