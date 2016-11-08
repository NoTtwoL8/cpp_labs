/*
Michael Dominguez
Jason Vega
Ebbin

Lab1 Part 3

*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct FullName
{
	string firstName;
	string lastName;
	char midInitial;
};

struct Student
{
	FullName name;
	float tests[3];
	float average;
	char letterGrade;
};


// Function Prototypes
float DetermineAverage(float[3]);
char determineLetterGrade(float);
Student getData();
void PrintStudent(Student);


int main() {
	const int SIZE = 24;
	Student roster[SIZE];
	
	for (int x = 0; x < SIZE; x++) {
		cout << "Enter data for student " << (x + 1) << ":" << endl;
		cout << "------------------------" << endl;
		roster[x] = getData();
	}
	
	for (int x = 0; x < SIZE; x++) {
		PrintStudent(roster[x]);
	}
	

	return 0;
}



float DetermineAverage(float array[3]) {

	float average = 0.0;
	for (int x = 0; x < 3; x++) {
		average += array[x];
	}
	average /= 3;
	return average;
}

char determineLetterGrade(float average) {
	char grade;
	if (average >= 90)
		grade = 'A';
	else if (average >= 80)
		grade = 'B';
	else if (average >= 70)
		grade = 'C';
	else if (average >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

Student getData() {

	Student student;	
	
	cout << "Please enter first name: ";
	getline(cin, student.name.firstName);
	cout << "Last name: ";
	getline(cin, student.name.lastName);
	cout << "Middle Initial: ";
	cin >> student.name.midInitial;

	cout << "Enter test score 1: ";
	cin >> student.tests[0];
	cout << "Enter test score 2: ";
	cin >> student.tests[1];
	cout << "Enter test score 3: ";
	cin >> student.tests[2];

	student.average = DetermineAverage(student.tests);

	student.letterGrade = determineLetterGrade(student.average);
	cin.ignore();
	return student;
}


void PrintStudent(Student student) {

	cout << "Student Name: " << student.name.firstName + " " + student.name.midInitial + " " + student.name.lastName << endl;
	cout << "Test 1: " << student.tests[0] << endl;
	cout << "Test 2: " << student.tests[1] << endl;
	cout << "Test 3: " << student.tests[2] << endl;
	cout << "Average: " << student.average << endl;
	cout << "Final Grade: " << student.letterGrade << endl;
}