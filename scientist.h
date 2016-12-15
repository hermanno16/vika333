#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>
#include <QString>

using namespace std;

class Scientist
{
public:
    //--Constructors--//
    Scientist(){}
    Scientist(string name, string gender, int yearOfBirth, string yearOfDeath, string scientistInfo);
    Scientist(int ID, string name, string gender, int yearOfBirth, string yearOfDeath, string scientistInfo);
    //--Set functions--//
    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(int yearOfBirth);
    void setYearOfDeath(string yearOfDeath);
    void setID(int ID);
    void setScientistInfo(string scientistInfo);
    //--Get funcitons--//
    int getID() const;
    string getName() const;
    string getGender() const;
    int getYearOfBirth() const;
    string getYearOfDeath() const;
    string getScientistInfo() const;
private:
    int _id;
    string _name;
    string _gender;
    int _yearOfBirth;
    string _yearOfDeath;
    string _scientistInfo;
};

#endif // SCIENTIST_H
