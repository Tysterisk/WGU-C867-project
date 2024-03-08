#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;

class roster
{
public:

	student* classRosterArray[5];
	roster(int classSize);
	~roster();
	const string getStudentID(int index) const;
	void parseStudentData(string StudentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
		int daysinCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll() const;
	void printAverageDaysInCourse(string studentID) const;
	void printInvalidEmails() const;
	void printByDegreeProgram(DegreeProgram degreeProgram) const;

protected:
	int classSize;
	int currentIndex = 0;
};

#endif // !ROSTER_H