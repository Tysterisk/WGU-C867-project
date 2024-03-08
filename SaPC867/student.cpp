#include "student.h"

//default constructor
student::student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}

//constructor proper
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, 
	int daysInCourse[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

//getters
const string student::getStudentID() const {
	return studentID;
}
const string student::getFirstName() const {
	return firstName;
}
const string student::getLastName() const {
	return lastName;
}
const string student::getEmailAddress() const {
	return emailAddress;
}
const int student::getAge() const {
	return age;
}
const int* student::getDaysInCourse() const {
	return daysInCourse;
}
const DegreeProgram student::getDegreeProgram() const {
	return degreeProgram;
}

//setters
void student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void student::setLastName(string lastName) {
	this->lastName = lastName;
}
void student::setEmailAdrress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void student::setAge(int age) {
	this->age = age;
}
void student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}
void student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//printers
void student::print() const {
	string denumDegree = "Error";

	switch (degreeProgram) {
	case SECURITY:
		denumDegree = "Security";
		break;
	case NETWORK:
		denumDegree = "Network";
		break;
	case SOFTWARE:
		denumDegree = "Software";
		break;
	}

	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " 
		<< age << "\tdaysInCourse {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] 
		<< "} Degree Program: " << denumDegree << endl;
}
void student::printStudentID() const {
	cout << studentID << endl;
}
void student::printFirstName() const {
	cout << firstName << endl;
}
void student::printLastName() const{
	cout << lastName << endl;
}
void student::printEmailAddress() const {
	cout << emailAddress << endl;
}
void student::printAge() const {
	cout << age << endl;
}
void student::printDaysInCourse() const {
	cout << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << endl;
}
void student::printDegreeProgram() const {
	switch (degreeProgram) {
	case SECURITY:
		cout << "Security" << endl;
		break;
	case NETWORK:
		cout << "Network" << endl;
		break;
	case SOFTWARE:
		cout << "Software" << endl;
		break;
	}
}