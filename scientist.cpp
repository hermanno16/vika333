#include "scientist.h"
using namespace std;

//--Constructors--//
Scientist::Scientist(int ID, string name, string gender, int yearOfBirth, string yearOfDeath)
{
    _id = ID;
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
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
