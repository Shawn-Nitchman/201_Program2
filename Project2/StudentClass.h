#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Student
{
public:
	// these are my setters I am defining them here since they are only one line of code.
	void SetFirstName(string fName)
	{
		firstName = fName;
	}
	void SetLastName(string lName)
	{
		lastName = lName;
	}
	void SetID(int sNum)
	{
		ID = sNum;
	}
	void SetFullName(string fulNam)
	{
		fullName = fulNam;
	}
	void SetGrades(string grade)
	{
		Grades = grade;
	}

	// these are my getters I am defining them here since they are only one line of code.
	string GetFirstName() const { return firstName; }
	string GetLastName() const { return lastName; }
	string GetFullName() const { return fullName; }
	string GetGrades() const { return Grades; }
	int GetID()const { return ID; }

private:
	string firstName;
	string lastName;
	string fullName;
	string Grades;
	int ID = -1;
};


class Students
{
public:
	void ReadData();
	void ReadGrades();
	void classRoster() const;
	void classRosterGrade() const;

private:
	vector<Student> AllStudents;
};
int menu();

void classRosterWeight();

