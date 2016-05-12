//========================================================================
//Program:		StructFun
//Author:		Austin Parrish
//Date:			01/25/2016
//Dev Env:		ICC
//Description:	Ask user for studetns names and GPA, and outputs that data
//========================================================================
#include<iostream>
#include<iomanip>
#include<string>

const int MAX_ENTRY = 10;

struct Student {
	std::string firstName[MAX_ENTRY];
	std::string lastName[MAX_ENTRY];
	float gpa[MAX_ENTRY];
};

char mainMenu();
void outputHeader();
void addStudent(Student& student, int& studentID);
void listStudent(const Student students, const int studentID);
void listStudents(const Student students, const int numOfStudents);
void listStudentsByGPA(const Student students, const int numOfStudents);

int main(void) {
	int numOfStudents = 0;
	bool keepGoing = true;
	Student students;

	//while loop that loops until the user is done
	while (keepGoing == true) {
		switch (mainMenu()) {
		case '1':
			if (numOfStudents < 10) {
				addStudent(students, numOfStudents);
			}
			else {
				std::cout << "Too manny students" << std::endl;
			}
			break;
		case '2':
			listStudents(students, numOfStudents);
			break;
		case '3':
			listStudentsByGPA(students, numOfStudents);
			break;
		case '4':
			std::cout << "Bye";
			keepGoing = false;
			break;
		default:
			std::cout << "Not a valid option" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}

//================================================================
// Function:		mainMenu
// Description:		Ask the user what acction they want to do.
// Arguments:		None
// Return value:	option
//================================================================
char mainMenu() {
	char option;
	std::cout << "Select an option: " << std::endl;
	std::cout << "1. Add a student" << std::endl;
	std::cout << "2. List students" << std::endl;
	std::cout << "3. List best students (by GPA)" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cin >> option;
	return option;
}

//================================================================
// Function:		outputHeader
// Description:		Outputs the header
// Arguments:		None
// Return value:	None
//================================================================
void outputHeader() {
	std::cout << std::setw(10) << "First Name";
	std::cout << std::setw(10) << "Last Name";
	std::cout << std::setw(10) << "GPA";
	std::cout << std::endl;
}

//================================================================
// Function:		addStudents
// Description:		Adds a student to the database
// Arguments:		student, studentID
// Return value:	student (Pass by reference)
//================================================================
void addStudent(Student& student, int& studentID) {
	std::cout << "Enter First Name: ";
	std::cin.get();
	getline(std::cin, student.firstName[studentID]);
	std::cout << std::endl;

	std::cout << "Enter Last Name: ";
	getline(std::cin, student.lastName[studentID]);
	std::cout << std::endl;

	std::cout << "Enter GPA: ";
	std::cin >> student.gpa[studentID];
	std::cout << std::endl;

	//Tells main function what the next id will be
	studentID++;
}

//================================================================
// Function:		listStudent
// Description:		outputs a student in the database
// Arguments:		students, studentID
// Return value:	none
//================================================================
void listStudent(const Student students, const int studentID) {
	std::cout << std::setw(10) << students.firstName[studentID];
	std::cout << std::setw(10) << students.lastName[studentID];
	std::cout << std::setw(10) << students.gpa[studentID];
	std::cout << std::endl;
}

//================================================================
// Function:		listStudents
// Description:		outputs a list of students in the database
// Arguments:		students, studentID
// Return value:	none
//================================================================
void listStudents(const Student students, const int numOfStudents) {
	outputHeader();
	for (int id = 0; id < numOfStudents; id++) {
		listStudent(students, id);
	}
}

//================================================================
// Function:		listStudentsByGPA
// Description:		outputs the highest gpa students
// Arguments:		students, studentID
// Return value:	none
//================================================================
void listStudentsByGPA(const Student students, const int numOfStudents) {
	int bestIndex[MAX_ENTRY] = { 0 };
	int indexCounter = 0;
	int bestScore = students.gpa[0];

	//Fist loop finds the best GPA
	for (int i = 0; i < numOfStudents; i++) {
		if (students.gpa[i] >= bestScore) {
			bestScore = students.gpa[i];
		}
	}

	//2nd loop finds the students that meet that GPA
	for (int i = 0; i < numOfStudents; i++) {
		if (students.gpa[i] >= bestScore) {
			bestIndex[indexCounter] = i;
			indexCounter++;
		}
	}

	//Final loop outputs those students
	outputHeader();
	for (int i = 0; i < indexCounter; i++) {
		listStudent(students, bestIndex[i]);
	}
}
