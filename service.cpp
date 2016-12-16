#include "service.h"
#include <cctype>


Service::Service()
{

}

void Service::openDataBase()
{
    _dAccess.startDatabase();
    _dAccess.openDataBase();
}

void Service::closeDataBase()
{
    _dAccess.closeDataBase();
}

//--Scientists functions--//
vector<Scientist> Service::getAllScientistsAtoZ()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsAtoZ();

    return allScientists;
}

vector<Scientist> Service::getAllScientistsZtoA()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsZtoA();

    return allScientists;
}
vector<Scientist> Service::getAllScientistsByYearOfBirthAsc()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsByYearOfBirthAsc();

    return allScientists;
}
void Service::updateComputerInDataBase(Computer updatedComputer)
{
    _dAccess.updateComputerInDataBase(updatedComputer);
}

void Service::updateScientistInDataBase(Scientist updatedScientist)
{
    _dAccess.updateScientistInDataBase(updatedScientist);
}

vector<Scientist> Service::getAllScientistsByYearOfBirthDes()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsByYearOfBirthDes();

    return allScientists;
}
vector<Scientist> Service::getAllDeadOrAliveScientistsAtoZ(char input)
{
    vector<Scientist> deadOrAliveScientists;

    if(input == '1')
    {
        deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();
    }
    else if(input == '2')
    {
        deadOrAliveScientists = _dAccess.getAllDeceasedScientistsAtoZ();
    }
    else
    {
        deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllDeceasedScientistsAtoZ().size(); i++)
        {
            deadOrAliveScientists.push_back(_dAccess.getAllDeceasedScientistsAtoZ()[i]);
        }
    }

    return deadOrAliveScientists;
}
vector<Scientist> Service::getAllDeceasedScientistsAtoZ()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllDeceasedScientistsAtoZ();

    return allScientists;
}
//Scientist - search functions.
vector<Scientist> Service::searchForScientists(string searchString)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientists(searchString);

    return allScientists;
}

Scientist Service::searchForScientistID(int searchID)
{
    vector<Scientist> aScientist = _dAccess.searchForScientistID(searchID);

    return aScientist[0];
}

vector<Scientist> Service::getScientistsByGenderAtoZ(char gender)
{
    vector<Scientist> genderScientists;

    if(gender == '1')
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();
    }
    else if(gender == '2')
    {
        genderScientists = _dAccess.getAllMaleScientistsAtoZ();
    }
    else
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllMaleScientistsAtoZ().size(); i++)
        {
            genderScientists.push_back(_dAccess.getAllMaleScientistsAtoZ()[i]);
        }
    }

    return genderScientists;
}
void Service::removeScientistFromDataBase(int idOfScientist)
{
    _dAccess.removeScientistFromDatabase(idOfScientist);
}
string Service::getScientistName(int idNumber)
{
    string aScientist;

    aScientist = _dAccess.getScientistName(idNumber);

    return aScientist;
}
//--Computer and Scientist functions--//
vector<Scientist> Service::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.connectComputerToScientist(idNumber);

    return allScientists;
}
vector<Computer> Service::connectScientistToComputer(int idNumber)
{
    vector<Computer> allComputers;

    allComputers = _dAccess.connectScientistToComputer(idNumber);

    return allComputers;
}
bool Service::addRelation(string scientistName, string computerName)
{
    bool relation = _dAccess.addScientistToComputer(scientistName, computerName);

    return relation;
}
void Service::removeRelationFromDatabase(int inputID, int inputCid)
{
    _dAccess.removeRelationFromDatabase(inputID,inputCid);
}
//--Computer functions--//
vector<Computer> Service::getAllComputersAtoZ()
{
    vector<Computer> allComputers;

    allComputers = _dAccess.getAllComputersAtoZ();

    return allComputers;
}
vector<Computer> Service::getAllComputersZtoA()
{
    vector<Computer> allComputers;

    allComputers = _dAccess.getAllComputersZtoA();

    return allComputers;
}
vector<Computer> Service::getAllTypesComputersAtoZ(char type)
{
    vector<Computer> typeComputer;
    vector<Computer> tempVectorComputer;
    if(type > '0' && type < '8')
    {
        if(type == '1')
        {
            typeComputer = _dAccess.getAllComputersTypeAtoZ();
        }
        else if(type == '2')
        {
            typeComputer = _dAccess.getAllComputersTypeElectronic();
        }
        else if(type == '3')
        {
            typeComputer = _dAccess.getAllComputersTypeMechanical();
        }
        else if(type == '4')
        {
            typeComputer = _dAccess.getAllComputersTypeElectronicMechanical();
        }
        else if(type == '5')
        {
            typeComputer = _dAccess.getAllComputersTransistor();
        }
        else if(type == '6')
        {
            typeComputer = _dAccess.getAllComputersTypeMicrocomputer();
        }
        else if (type == '7')
        {
            typeComputer = _dAccess.getAllComputersTypeTernary();
        }
        return typeComputer;
    }
    else
    {
        cout << "  > invalid input!" << endl;
        return tempVectorComputer;
    }
}
vector<Computer> Service::getAllBuildYearComputers(string yearBuilt)
{
    vector<Computer> yearBuiltComputer;

    if(yearBuilt == "1")
    {
        yearBuiltComputer = _dAccess.getAllComputersYearBuiltAtoZ();
    }
    else if(yearBuilt == "2")
    {
        yearBuiltComputer = _dAccess.getAllComputersYearBuiltZtoA();
    }

    return yearBuiltComputer;
}
vector<Computer> Service::getAllDevelopmentAndOriginalComputers(string development)
{
    vector<Computer> developmentComputer;

    if (development == "1")
    {
        developmentComputer = _dAccess.getAllComputersOriginal();
    }
    else if (development == "2")
    {
        developmentComputer = _dAccess.getAllComputersDeveloped();

    }
    else if (development == "3")
    {
        developmentComputer =_dAccess.getAllComputersDevelopedAndOriginal();
    }

    return developmentComputer;
}
//--Computer Search Functions
vector<Computer> Service::searchForComputers(string searchString)
{

    vector<Computer> allComputers;

    allComputers = _dAccess.searchForComputers(searchString);

    return allComputers;

}
Computer Service::searchForComputerID(int searchID)
{
    vector<Computer> aComputer = _dAccess.searchForComputerID(searchID);

    return aComputer[0];
}
string Service::getComputerName(int idNumber)
{
    string aComputer;

    aComputer = _dAccess.getComputerName(idNumber);

    return aComputer;
}
//-- Valid functions --//
void Service::addScientistToData(Scientist newScientist)
{
    _dAccess.addScientistToDataBase(newScientist);
}

void Service::addComputerToData(Computer newComputer)
{
    _dAccess.addComputerToDataBase(newComputer);
}
void Service::removeComputerFromDataBase(int idOfComputer)
{
    _dAccess.removeComputerFromDatabase(idOfComputer);
}

bool Service::isScientistAlreadyInDatabase(Scientist newScientist)
{
    if(_dAccess.isScientistAlreadyInDatabase(newScientist))
    {
        return true;
    }

    return false;
}


bool Service::isYearOfBirthOfScientistValid(Scientist newScientist)
{
    bool yearOfBirthCheck1 = false;
    bool yearOfBirthCheck2 = false;


    if(newScientist.getYearOfBirth() <= YEARTODAY)
    {
        yearOfBirthCheck1 = true;
    }

    if(newScientist.getYearOfBirth() <= atoi(newScientist.getYearOfDeath().c_str()))
    {
        yearOfBirthCheck2 = true;
    }

    if(newScientist.getYearOfDeath() == "N/A")
    {
       yearOfBirthCheck2 = true;
    }

    return (yearOfBirthCheck1 && yearOfBirthCheck2);
}
void Service::fixInputYearOfDeath(Scientist& newScientist)
{
    string yearOfDeath = newScientist.getYearOfDeath();

    yearOfDeath.at(0) = toupper(yearOfDeath.at(0));
    yearOfDeath.at(2) = toupper(yearOfDeath.at(2));

    newScientist.setYearOfDeath(yearOfDeath);
}

void Service::fixInputNameScientist(Scientist& newScientist)
{
    string name = newScientist.getName();

    name = name.substr(0,40);
    name.at(0) = toupper(name.at(0));

    for(unsigned int i = 1; i < name.size(); i++)
    {
        if (name.at(i - 1) == ' ')
        {
            name.at(i) = toupper(name.at(i));
        }
        else
        {
            name.at(i) = tolower(name.at(i));
        }
    }
    newScientist.setName(name);
}

void Service::fixAddComputerType(Computer& newComputer)
{
    string inputType = newComputer.getType();

    inputType = inputType.substr(0,21);

    inputType.at(0) = toupper(inputType.at(0));

    for(unsigned int i = 1; i < inputType.size(); i++)
    {
        inputType.at(i) = tolower(inputType.at(i));
    }

    newComputer.setType(inputType);
}

bool Service::isAddComputerYearBuiltValid(Computer newComputer)
{
    int yearBuilt = newComputer.getYearBuilt();

    if((yearBuilt <= YEARTODAY) && (yearBuilt > 0))
    {
        return true;
    }

    return false;
}
bool Service::isAddComputerNameValid(Computer newComputer)
{
    bool check1 = false;
    bool check2 = false;

    string name = newComputer.getName();

    if(!_dAccess.isComputerNameAlreadyInDatabase(name))
    {
        check1 = true;
    }

    if(name.length() > 0)
    {
        check2 = true;
    }

    return(check1 && check2);
}
bool Service::isAddComputerTypeValid(Computer newComputer)
{
    string type = newComputer.getType();

    if(type.length() > 0)
    {
        return true;
    }

    return false;
}
