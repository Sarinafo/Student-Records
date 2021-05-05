
#include "student.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;


using namespace std;


Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age;
    this->days = new int[numberOfDays];
    for (int i = 0; i < numberOfDays; i++) this->days[i] = 0;
    this->degreeType = DegreeProgram::UNDECIDED;
}
//student constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeType)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->days = new int[numberOfDays];
    for (int i = 0; i < 3; i++) this->days[i] = days[i];
    this->degreeType = degreeType;
}


//getters and setters
string Student::getstudentID() { return studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemail() { return this->email; }
int Student::getage() { return this->age; }
int* Student::getcourseDays() { return this->days; }
DegreeProgram Student::getDegreeType() { return this->degreeType; }

void Student::setstudentID(string ID) { this->studentID = ID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemail(string email) { this->email = email; }
void Student::setage(int age) { this->age = age; }
void Student::setcourseDays(int days[])
{
    for (int i = 0; i < 3; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeProgram degreeType) { this->degreeType = degreeType; }
//header
void Student::printHeader()
{
    cout << "Student ID\tFirst Name\tLast Name\tEmail\tAge\tDays in Course\tDegree Program\n";

}
//print 
void Student::print()
{
    cout << studentID;
    cout << "\tFirst Name: " << firstName;
    cout << "\tLast Name: " << lastName;
    cout << "\tEmail: " << email;
    cout << "\tAge: " << age;
    cout << "\t Days In Course: " << days[0] << "," << days[1] << "," << days[2];
    cout << "\tDegree Program: " << degreeTypeStrings[degreeType]; cout << endl;
}


Student::~Student()
{
    
}


