#include "roster.h"
#include <iostream>
#include <string>
// parses each set of data in the student data table
void Roster::parse(string studentdata)
{
    int rhs = studentdata.find(",");
    string studentID = studentdata.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string emailAddress = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string degree = studentdata.substr(lhs, rhs - lhs);
    
    DegreeProgram deg = SECURITY;
    
    if (degree == "NETWORK") {
        deg = NETWORK;
    }
    if (degree == "SOFTWARE") {
        deg = SOFTWARE;
    }
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, deg);
}
// sets the instance variable and updates roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int  age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType)
{
    int numberOfDays[3] = {
        daysInCourse1, daysInCourse2, daysInCourse3
    };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeType);
    /*if (degreeType == NETWORK) classRosterArray[max] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeType);
    else if (degreeType == SECURITY) classRosterArray[max] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeType);
    else classRosterArray[max] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeType);*/
}
// prints all student data
void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        classRosterArray[i]->print();
    }
}

//prints the average number of days in student data table
void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++){
                if (classRosterArray[i]->getstudentID() == studentID)
                {
                    cout << studentID << ": ";
                    cout << (classRosterArray[i]->getcourseDays()[0]
                        + classRosterArray[i]->getcourseDays()[1]
                        + classRosterArray[i]->getcourseDays()[2]) / 3.0 << endl;
                }
            }
}

//prints students with invalid emails
void Roster::printInvalidEmails()
{
    bool none = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        string si = (classRosterArray[i]->getemail());
        if (si.find('@') == string::npos ||
            si.find('.') == string::npos ||
            si.find(' ') != string::npos)
        {
            none = true;
            cout << classRosterArray[i]->getstudentID() << ": " << classRosterArray[i]->getemail() << std::endl;
        }
    }
    if (!none) cout << "NONE" << std::endl;
}

//prints students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeType)
{
    string degreeString;
        if (degreeType == SECURITY) {
            degreeString = "SECURITY";
        }
        else if (degreeType == NETWORK) {
            degreeString = "NETWORK";
        }
        else if (degreeType == SOFTWARE) {
            degreeString = "SOFTWARE";
        }
        else {
            degreeString = "ERROR";
        }
        cout << "Students with degree program: " << degreeString << endl;
        int numStu = 0;
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i]->getDegreeType() == degreeType) {
                classRosterArray[i]->print();
                ++numStu;
            }
        }
        if (numStudents == 0) {
            cout << "No students with this degree found." << endl;
        }
        return;
    }


//removes students by thei student ID
void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (classRosterArray[i]->getstudentID() == studentID){
            success = true;
            if (i < numStudents - 1){
                Student* temp = classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed from table." << std::endl << std::endl;
        this->printAll();
    }
    else cout << "Student with the ID " << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster() //Destructor
{
    return;
    
}
