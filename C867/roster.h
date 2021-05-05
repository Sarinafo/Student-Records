#pragma once
#include "student.h"
#include <string>
#include <iostream>
using std::cout;


class Roster {

public:

    int lastIndex = -1;
    
    const static int numStudents = 5;

    Student* classRosterArray[numStudents];
    
    void parse (string row);
    //sets instance variables and updates roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    //prints all of students
    void printAll();
    //prints the students average number of days in courses
    void printAverageDays(string studentID);
    //prints students with invalid email addresses
    void printInvalidEmails();
    //prints students by degree programs
    void printByDegreeProgram(DegreeProgram degreeType);
    //removes student data
    void removeStudentByID (string studentID);

    Student* getStudentAt(int index);

    //The destructor
    ~Roster();
};
