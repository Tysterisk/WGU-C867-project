// SaPC867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "degree.h"
#include "roster.h"
#include "student.h"


int main()
{
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Thomas,Swade,tswade@wgu.edu,32,5,3,38,SOFTWARE"
    };

    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "Program made in C++ using Microsoft Visual Studio" << endl;
    cout << "WGU Student ID: 010537018" << endl;
    cout << "Written by Thomas Swade" << endl;

    cout << "\n\nAdding students to Roster." << endl;
    roster* classRoster = new roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parseStudentData(studentData[i]);
    }

    cout << "\n\nPrinting all students." << endl;
    classRoster->printAll();

    cout << "\n\nPrinting invalid emails." << endl;
    classRoster->printInvalidEmails();

    cout << "\n\nPrinting average days in class." << endl;
    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
    }

    cout << "\n\nPrinting by degree program." << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << "\n\nRemoving studentID A3." << endl;
    classRoster->remove("A3");

    cout << "\n\nPrinting all students again." << endl;
    classRoster->printAll();

    cout << "\n\nRemoving studentID A3 again (expected error)." << endl;
    classRoster->remove("A3");

    cout << "\n\nDeallocating memory with class destructor." << endl;
    classRoster->~roster();
    delete classRoster;
}


