#include "computer.h"
using namespace std;

//--Constructors--//
Computer::Computer(int ID,
                   string name,
                   string type,
                   int yearBuilt,
                   string development,
                   string computerInfo)
{
    _id = ID;
    _name = name;
    _type = type;
    _yearBuilt = yearBuilt;
    _development = development;
    _computerInfo = computerInfo;
}
//--Set functions--//
void Computer::setId(int ID)
{
    _id = ID;
}
void Computer::setName(string name)
{
    _name = name;
}
void Computer::setType(string type)
{
    _type = type;
}
void Computer::setYearBuilt(int yearBuilt)
{
    _yearBuilt = yearBuilt;
}
void Computer::setDevelopment(string development)
{
    _development = development;
}
void Computer::setComputerInfo(string computerInfo)
{
    _computerInfo = computerInfo;
}
//--Get funcitons--//
int Computer::getId() const
{
    return _id;
}
string Computer::getName() const
{
    return _name;
}
string Computer::getType() const
{
    return _type;
}
int Computer::getYearBuilt() const
{
    return _yearBuilt;
}
string Computer::getDevelopment() const
{
    return _development;
}
string Computer::getComputerInfo() const
{
    return _computerInfo;
}
