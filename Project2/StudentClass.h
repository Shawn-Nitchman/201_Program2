#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student
{
public:
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetID(int sNum);

	//void GetFirstName();
	//void GetLastName();
	int GetID();

private:
	string firstName;
	string lastName;
	int ID = -1;
};

class Students
{
public:
	void InputStudents();
	void print();

private:
	vector<Student> AllStudents;
};
int menu();

void classRoster();
void classRosterGrade();
void classRosterWeight();

