#include "roster.h"
#include <string>
using std::endl;

Roster classRoster;

int main()
{
    cout << "Name: Sarina Foreman\n";
    cout << "Student ID:001109984\n";
    cout << "Course Title: Scripting and Programming Languages (C867)\n";
    cout << "Language Used: C++\n";
    
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Sarina,Foreman,sfore16@wgu.edu,29,20,32,22,SOFTWARE"
        };
    

    const int numStudents = 5;
    Roster roster;
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    
    cout << "Displaying students with invalid email addresses:" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
  
    cout << "Displaying Average Days in Course: " << endl;
        for (int i = 0; i < numStudents; i++)
        {
            roster.printAverageDays(roster.classRosterArray[i]->getstudentID());
        }
    
   // for (int i = 0; i < 3; i++){
       // cout << "Displaying by Degree Program: " << degreeTypeStrings[i] << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;
   // }
    
    
    roster.removeStudentByID("A3");
    cout << endl;
    

    roster.removeStudentByID("A3");
    cout << endl; 
    
  
    return 0;
}
