#ifndef Service_H
#define Service_H

#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"
#include "computer.h"
#include <algorithm>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
using namespace std;
const int YEARTODAY = 2016;


class Service
{
public:
    //--Constructor--//
    Service();
    //--Scientists--//
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByYearOfBirthAsc();
    vector<Scientist> getAllScientistsByYearOfBirthDes();
    vector<Scientist> getAllDeadOrAliveScientistsAtoZ(char input);
    //Scientist - search functions.
    vector<Scientist> searchForScientists(string searchString);
    vector<Scientist> getScientistsByGenderAtoZ(char gender);
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    string getScientistName(int idNumber);
    Scientist searchForScientistID(int searchID);
    //Scientist - other functions.
    void removeScientistFromDataBase(int idOfScientist);
    //--Computer--//
    vector<Computer> getAllComputersAtoZ();
    vector<Computer> getAllComputersZtoA();
    vector<Computer> getAllTypesComputersAtoZ(char type);
    vector<Computer> getAllComputersDevelopment();
    vector<Computer> getAllBuildYearComputers(string yearBuilt);
    vector<Computer> getAllDevelopmentAndOriginalComputers(string development);
    //Computer Search functions
    vector<Computer> searchForComputers(string searchstring);
    Computer searchForComputerID(int searchID);
    string getComputerName(int idNumber);
    //Computer - other functions
    void removeComputerFromDataBase(int idOfComputer);
    //Connection tables
    vector<Scientist> connectComputerToScientist(int idNumber);
    vector<Computer> connectScientistToComputer(int idNumber);
    bool addRelation(string scientistName, string computerName);
    void removeRelationFromDatabase(int inputID,int inputCid);
    //--Check functions--//
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    bool isScientistAlreadyInDatabase(Scientist newScientist);
    bool isYearOfBirthOfScientistValid(Scientist newScientist);
    bool isYearOfDeathOfScientistValid(string yearOfBirth);
    bool isAddComputerValid(string name, string yearBuilt, string type, string development);
    void addScientistToData(Scientist newScientist);
    void addComputerToData(Computer newComputer);
    bool inputNameValid(string input);
    void fixInputNameScientist(Scientist& newScientist);
    void fixInputGenderScientist(string& inputGender);
    void fixInputYearOfDeath(Scientist &newScientist);

    void fixAddComputerType(Computer& newComputer);
    bool isAddComputerYearBuiltValid(Computer newComputer);
    bool isAddComputerNameValid(Computer newComputer);
    bool isAddComputerTypeValid(Computer newComputer);
    //--Open database--//
    void openDataBase();
    void closeDataBase();
private:
    DataAccess _dAccess;
};


#endif // Service_H
