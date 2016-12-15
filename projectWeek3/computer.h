#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    //--Constructors--//
    Computer(){}
    Computer(string name, string type, int yearBuilt, string development, string computerInfo);
    Computer(int ID, string name, string type, int yearBuilt, string development, string computerInfo);
    //--Set functions--//
    void setComputerInfo(string computerInfo);
    void setId(int ID);
    void setName(string name);
    void setType(string type);
    void setYearBuilt(int yearBuilt);
    void setDevelopment(string developement);
    //--Get funcitons--//
    string getComputerInfo();
    int getId() const;
    string getName() const;
    string getType() const;
    int getYearBuilt() const;
    string getDevelopment() const;

private:
    int    _id;
    string _computerInfo;
    string _name;
    string _type;
    int    _yearBuilt;
    string _development;

};

#endif // COMPUTER_H
