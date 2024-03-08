#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class student
{
public:
	student();
	student(string studentID, string firstName, string lastName, string emailAddress, int age, 
		int daysInCourse[3], DegreeProgram degreeProgram);

	//getters
	const string getStudentID() const;
	const string getFirstName() const;
	const string getLastName() const;
	const string getEmailAddress() const;
	const int getAge() const;
	const int* getDaysInCourse() const;
	const DegreeProgram getDegreeProgram() const;

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAdrress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//printers
	void print() const;
	void printStudentID() const;
	void printFirstName() const;
	void printLastName() const;
	void printEmailAddress() const;
	void printAge() const;
	void printDaysInCourse() const;
	void printDegreeProgram() const;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	unsigned int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
};

#endif // !STUDENT_H