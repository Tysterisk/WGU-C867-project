#include "roster.h"

//build roster in class constructor
roster::roster(int classSize) {
	this->classSize = classSize;
	for (int i = 0; i < classSize; i++) {
		this->classRosterArray[i] = new student;
	}
	return;
}

//unallocate memory in class destructor
roster::~roster() {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
	return;
}

const string roster::getStudentID(int index) const {
	return classRosterArray[index]->getStudentID();
}

//parse data by finding first comma, getting data before it, and removing parsed information to easily get the next point of data
void roster::parseStudentData(string StudentData) {
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	int commaPos = 0;
	string degreeProgramString;

	classRosterArray[currentIndex] = new student();

	commaPos = StudentData.find(",");
	studentID = StudentData.substr(0, commaPos);
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	firstName = StudentData.substr(0, commaPos);
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	lastName = StudentData.substr(0, commaPos);
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	emailAddress = StudentData.substr(0, commaPos);
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	age = stoi(StudentData.substr(0, commaPos));
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	daysInCourse[0] = stoi(StudentData.substr(0, commaPos));
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	daysInCourse[1] = stoi(StudentData.substr(0, commaPos));
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	daysInCourse[2] = stoi(StudentData.substr(0, commaPos));
	StudentData.erase(0, commaPos + 1);

	commaPos = StudentData.find(",");
	degreeProgramString = StudentData.substr(0, commaPos);

	if (degreeProgramString == "SECURITY") {
		classRosterArray[currentIndex]->setDegreeProgram(SECURITY);
	}
	else if (degreeProgramString == "NETWORK") {
		classRosterArray[currentIndex]->setDegreeProgram(NETWORK);
	}
	else if (degreeProgramString == "SOFTWARE") {
		classRosterArray[currentIndex]->setDegreeProgram(SOFTWARE);
	}

	classRosterArray[currentIndex]->setStudentID(studentID);
	classRosterArray[currentIndex]->setFirstName(firstName);
	classRosterArray[currentIndex]->setLastName(lastName);
	classRosterArray[currentIndex]->setEmailAdrress(emailAddress);
	classRosterArray[currentIndex]->setAge(age);
	classRosterArray[currentIndex]->setDaysInCourse(daysInCourse[0], daysInCourse[1], daysInCourse[2]);

	currentIndex++;
}
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, 
	int daysInCourse1, int daysinCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysInCourse[3] = { daysInCourse1,daysinCourse2,daysInCourse3 };

	classRosterArray[classSize] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void roster::remove(string studentID) {

	bool studentRemoved = 0;

	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				cout << studentID << " removed." << endl;
				studentRemoved = 1;
				break;
			}
		}
	}

	if (!studentRemoved) {
		cout << "Error:  ID " << studentID << " not found." << endl;
	}
}

void roster::printAll() const {

	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr){
			classRosterArray[i]->print();
		}
	}

}

void roster::printAverageDaysInCourse(string studentID) const {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {

				cout << "ID " << studentID << " averages " << ((classRosterArray[i]->getDaysInCourse()[0] + 
					classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3) 
					<< " days per class." << endl;
			}
		}
	}
}

void roster::printInvalidEmails() const {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			string currentEmail = classRosterArray[i]->getEmailAddress();

			if (currentEmail.find("@") == string::npos) {
				cout << "Student " << classRosterArray[i]->getStudentID() << " has an invalid email address - " 
					<< currentEmail << " - is missing the @ sign." << endl;
			}
			else if (currentEmail.find(".") == string::npos) {
				cout << "Student " << classRosterArray[i]->getStudentID() << " has an invalid email address - " 
					<< currentEmail << " - is missing a period." << endl;
			}
			else if (currentEmail.find(" ") != string::npos) {
				cout << "Student " << classRosterArray[i]->getStudentID() << " has an invalid email address - " 
					<< currentEmail << " - contains a space." << endl;
			}
		}
	}
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) const {

	int studentNum = 0;

	cout << "Students enrolled in ";

	switch (degreeProgram) {
	case SECURITY:
		cout << "Security:\n" << endl;
		break;
	case NETWORK:
		cout << "Network:\n" << endl;
		break;
	case SOFTWARE:
		cout << "Software:\n" << endl;
		break;
	}

	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
				classRosterArray[i]->print();
				studentNum++;
			}
		}
	}

	if (studentNum == 0) {
		cout << "None." << endl;
	}
}