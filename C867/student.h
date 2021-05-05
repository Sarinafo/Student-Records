

#ifndef student_h
#define student_h
#include <string>
#include "degree.h"

using namespace std;

class Student
{

public:
    const static int numberOfDays = 3;
private:
    //variables
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string email = "";
    int age;
    int* days;
    DegreeProgram degreeType = DegreeProgram::UNDECIDED;
public:
    //constructor
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeType);
    ~Student(); //destructor

    //getters and setters
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemail();
    int getage();
    int* getcourseDays();
    DegreeProgram getDegreeType();


    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemail(string email);
    void setage(int age);
    void setcourseDays(int days[]);
    void setDegreeType(DegreeProgram dt);

    static void printHeader(); //displays a header for data to follow

    void print();// prints student data

};


#include <stdio.h>

#endif /* student_hpp */
