#include "scientist.h"
using namespace std;

//--Constructors--//
Scientist::Scientist(int ID, string name, string gender, int yearOfBirth, string yearOfDeath, string scientistInfo)
{
    _id = ID;
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
    _scientistInfo = scientistInfo;
}
//--Get funcitons--//
int Scientist::getID() const
{
    return _id;
}
string Scientist::getName() const
{
    return _name;
}
string Scientist::getGender() const
{
    return _gender;
}
int Scientist::getYearOfBirth() const
{
    return _yearOfBirth;
}
string Scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}
string Scientist::getScientistInfo() const
{
    return _scientistInfo;
}
//--Set functions--//
void Scientist::setID(int ID)
{
    _id = ID;
}
void Scientist::setName(string name)
{
    _name = name;
}
void Scientist::setGender(string gender)
{
    _gender = gender;
}
void Scientist::setYearOfBirth(int yearOfBirth)
{
    _yearOfBirth = yearOfBirth;
}
void Scientist::setYearOfDeath(string yearOfDeath)
{
    _yearOfDeath = yearOfDeath;
}
void Scientist::setScientistInfo(string scientistInfo)
{
    _scientistInfo = scientistInfo;
}
