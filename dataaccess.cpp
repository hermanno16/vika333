#include "dataaccess.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>

using namespace std;
//-- Constructor --//
DataAccess::DataAccess()
{

}
DataAccess::~DataAccess()
{
    _dataBaseMain.close();
}
//-- Scientist --//
//Scientist - SQL functions.
vector<Scientist> DataAccess::getAllScientistInfoFromDataBase(QString queryCommand)
{
    vector<Scientist> allScientists;

    QSqlQuery query;
    query.prepare(queryCommand);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();
        QString scientistInfo = query.value(query.record().indexOf("Information")).toString();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath.toStdString(),
                    scientistInfo.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::getAllScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllScientistsZtoA()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY FirstName Desc");
}
vector<Scientist> DataAccess::getAllScientistsByYearOfBirthAsc()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY YearOfBirth Asc");
}
vector<Scientist> DataAccess::getAllScientistsByYearOfBirthDes()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY YearOfBirth Desc");
}
vector<Scientist> DataAccess::getAllMaleScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Male' ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllFemaleScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Female' ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllAliveScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NULL ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllDeceasedScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NOT NULL ORDER BY FirstName Asc");
}
//Scientist - search functions.
vector<Scientist> DataAccess::searchForScientists(string searchString)
{
    QString qSearchString = QString::fromStdString(searchString);

    vector<Scientist> allScientists;

    allScientists.clear();

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE (FirstName) LIKE '%"+qSearchString+"%' "
                  "or (Gender) LIKE '%"+qSearchString+"%' "
                  "or (YearOfBirth) LIKE '%"+qSearchString+"%' "
                  "or (YearOfDeath) LIKE '%"+qSearchString+"%' ");
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();
        QString scientistInfo = query.value(query.record().indexOf("Information")).toString();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath.toStdString(),
                    scientistInfo.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}

vector<Scientist> DataAccess::searchForScientistID(int searchID)
{
    vector<Scientist> oneScientist;

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE ID = (:id)");
    query.bindValue(":id", searchID);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();
        QString scientistInfo = query.value(query.record().indexOf("Information")).toString();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath.toStdString(),
                    scientistInfo.toStdString()
                    );

        oneScientist.push_back(newScientist);
    }

    return oneScientist;
}

//Scientist - other functions.
void DataAccess::removeScientistFromDatabase(int idOfScientist)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Scientists where ID = (:id)");
    query.bindValue(":id",idOfScientist);

    query.exec();
}
void DataAccess::removeRelationFromDatabase(int id, int cID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ConnectionTable WHERE ID = (:id) AND Cid = (:cid)");
    query.bindValue(":id", id);
    query.bindValue(":cid", cID);
    query.exec();
}
bool DataAccess::isScientistAlreadyInDatabase(Scientist newScientist)
{
    QString qSearchName = QString::fromStdString(newScientist.getName());

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE (FirstName) LIKE '%"+qSearchName+"%'");

    if(query.exec())
    {
        if (query.next())
        {
            return true;
        }
    }
    return false;
}
bool DataAccess::isComputerNameAlreadyInDatabase(string& inputName)
{
    cout << inputName << endl;
    QString qSearchName = QString::fromStdString(inputName);

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE (ComputerName) LIKE '%"+qSearchName+"%'");

    if(query.exec())
    {
        if (query.next())
        {
            return true;
        }
    }
    return false;
}
void DataAccess::addScientistToDataBase(Scientist newScientist)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Scientists (FirstName, YearOfBirth, YearOfDeath, Gender) "
                  "VALUES (:name, :yearofbirth, :yearofdeath, :gender)");

    query.bindValue(":name", QString::fromStdString(newScientist.getName()));
    query.bindValue(":yearofbirth", newScientist.getYearOfBirth());
    query.bindValue(":yearofdeath", QString::fromStdString(newScientist.getYearOfDeath()));
    query.bindValue(":gender", QString::fromStdString(newScientist.getGender()));
    query.exec();

}
bool DataAccess::addScientistToComputer(string scientistName, string computerName)
{
    bool existCheck = false;
    int ID, Cid;

    vector<Scientist> theScientist = searchForScientists(scientistName);
    if(theScientist.size()!=0)
    {
        ID = theScientist[0].getID();
    }
    else
    {
        return false;
    }
    vector<Computer> theComputer = searchForComputers(computerName);
    if(theComputer.size()!=0)
    {
        Cid = theComputer[0].getId();
    }
    else
    {
        return false;
    }

    vector<Scientist> relationCheck = connectComputerToScientist(Cid); // Checks if there are results of realation to a computer.
    if(relationCheck.size() == 0)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO ConnectionTable (Cid, ID) VALUES (:cid, :id)");
        query.bindValue(":cid", Cid);
        query.bindValue(":id", ID);
        query.exec();
    }
    else if(relationCheck.size() > 0)
    {
        for(unsigned int i = 0; i < relationCheck.size(); i++)
        {
            if(relationCheck[i].getID() == ID)
            {
                existCheck = true;
            }
        }
    }
    if(existCheck == true)
    {
        return false;
    }
    else if(existCheck == false)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO ConnectionTable (Cid, ID) VALUES (:cid, :id)");
        query.bindValue(":cid", Cid);
        query.bindValue(":id", ID);
        query.exec();

        return true;
    }
}
//-- Computers--//
//Computers - SQL functions.
void DataAccess::addComputerToDataBase(Computer newComputer)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Computers (ComputerName, YearBuilt, Type, Development, Information) "
                  "VALUES (:computername, :yearbuilt, :type, :development, :information)");

    query.bindValue(":computername", QString::fromStdString(newComputer.getName()));
    query.bindValue(":yearbuilt", newComputer.getYearBuilt());
    query.bindValue(":type", QString::fromStdString(newComputer.getType()));
    query.bindValue(":development", QString::fromStdString(newComputer.getDevelopment()));
    query.bindValue(":information", QString::fromStdString(newComputer.getComputerInfo()));
    query.exec();
}
void DataAccess::removeComputerFromDatabase(int idOfComputer)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Computers where Cid = (:cid)");
    query.bindValue(":cid",idOfComputer);
    query.exec();
}
vector<Computer> DataAccess::getAllComputerInfoFromDataBase(QString queryCommand)
{
    vector<Computer> allComputers;

    QSqlQuery query;
    query.prepare(queryCommand);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("Cid")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int yearBuilt = query.value(query.record().indexOf("YearBuilt")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();
        QString information = query.value(query.record().indexOf("Information")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    yearBuilt,
                    development.toStdString(),
                    information.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;
}
vector<Computer> DataAccess::getAllComputersAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT Cid,ComputerName,Type,YearBuilt,Development, Information FROM Computers ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersZtoA()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY ComputerName Desc");
}
vector<Computer> DataAccess::getAllComputersYearBuiltAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY YearBuilt Asc");
}
vector<Computer> DataAccess::getAllComputersYearBuiltZtoA()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY YearBuilt Desc");
}
vector<Computer> DataAccess::getAllComputersTypeAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY Type Asc");
}
vector<Computer> DataAccess::getAllComputersTypeElectronic()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Electronic' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersTypeElectronicMechanical()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Electronic/Mechanical' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersTypeMechanical()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Mechanical' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersTransistor()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Transistor' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersTypeMicrocomputer()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Microcomputer' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersTypeTernary()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Type = 'Ternary' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersDeveloped()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Development = 'Developed' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersOriginal()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers WHERE Development = 'Original' ORDER BY ComputerName Asc");
}
vector<Computer> DataAccess::getAllComputersDevelopedAndOriginal()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY Development Asc");
}
//Computers - search functions
vector<Computer> DataAccess::searchForComputers(string searchString)
{
    QString qSearchString = QString::fromStdString(searchString);

    vector<Computer> allComputers;

    allComputers.clear();

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE (ComputerName) LIKE '%"+qSearchString+"%' "
                  "or (Type) LIKE '%"+qSearchString+"%' "
                  "or (YearBuilt) LIKE '%"+qSearchString+"%' "
                  "or (Development) LIKE '%"+qSearchString+"%' ");
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("Cid")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int yearBuilt = query.value(query.record().indexOf("YearBuilt")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();
        QString information = query.value(query.record().indexOf("Information")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    yearBuilt,
                    development.toStdString(),
                    information.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;
}
vector<Computer> DataAccess::searchForComputerID(int searchID)
{
    vector<Computer> aComputer;

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE Cid = (:something)");
    query.bindValue(":something", searchID);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("Cid")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int yearBuilt = query.value(query.record().indexOf("YearBuilt")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();
        QString information = query.value(query.record().indexOf("Information")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    yearBuilt,
                    development.toStdString(),
                    information.toStdString()
                    );

        aComputer.push_back(newComputer);
    }

    return aComputer;
}

string DataAccess::getComputerName(int idNumber)
{
    int id = idNumber;

    string aComputer;

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE Cid = (:something)");
    query.bindValue(":something", id);
    query.exec();

    while(query.next())
    {

        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        aComputer = name.toStdString();
    }
    return aComputer;
}
string DataAccess::getScientistName(int idNumber)
{
    int id = idNumber;

    string aScientist;

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE ID = (:something)");
    query.bindValue(":something", id);
    query.exec();

    while(query.next())
    {
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        aScientist = name.toStdString();
    }

    return aScientist;
}
void DataAccess::startDatabase()
{
    _dataBaseMain = QSqlDatabase::addDatabase("QSQLITE");
    _dataBaseMain.setDatabaseName("Verk1.sqlite");
}

//-- Connect to database --//
void DataAccess::openDataBase()
{
    startDatabase();
    if(!_dataBaseMain.isOpen())
        _dataBaseMain.open();

}
void DataAccess::closeDataBase()
{
    _dataBaseMain.close();
}

QSqlDatabase DataAccess::readDataBase()
{
    return _dataBaseMain;
}//--Scientists and computers--//
vector<Scientist> DataAccess::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Scientists, ConnectionTable "
                  "WHERE Scientists.ID = ConnectionTable.ID "
                  "AND ConnectionTable.Cid =  (:something)");
    query.bindValue(":something", idNumber);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();
        QString scientistInfo = query.value(query.record().indexOf("Information")).toString();


        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath.toStdString(),
                    scientistInfo.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Computer> DataAccess::connectScientistToComputer(int idNumber)
{
    vector<Computer> allComputers;

    QSqlQuery query;

    query.prepare("SELECT * FROM Computers, ConnectionTable "
                  "WHERE Computers.Cid = ConnectionTable.Cid "
                  "AND ConnectionTable.ID = (:something)");
    query.bindValue(":something", idNumber);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("Cid")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int yearBuilt = query.value(query.record().indexOf("YearBuilt")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();
        QString computerInfo = query.value(query.record().indexOf("Information")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    yearBuilt,
                    development.toStdString(),
                    computerInfo.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;
}

