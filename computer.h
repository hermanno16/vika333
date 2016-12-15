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
    void setId(int ID);
    void setName(string name);
    void setType(string type);
    void setYearBuilt(int yearBuilt);
    void setDevelopment(string developement);
    void setComputerInfo(string computerInfo);
    //--Get funcitons--/
    int getId() const;
    string getName() const;
    string getType() const;
    int getYearBuilt() const;
    string getDevelopment() const;
    string getComputerInfo() const;

private:
    int    _id;
    string _name;
    string _type;
    int    _yearBuilt;
    string _development;
    string _computerInfo;

};

#endif // COMPUTER_H
