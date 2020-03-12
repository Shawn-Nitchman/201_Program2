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
	// I made all my grades a seperate vairable since I have to mess with them so I did not store them as a string
	void SetQuiz1(int quiz1)
	{
		Quiz1 = quiz1;
	}
	void SetQuiz2(int quiz2)
	{
		Quiz2 = quiz2;
	}
	void SetTest1(int test1)
	{
		Test1 = test1;
	}
	void SetTest2(int test2)
	{
		Test2 = test2;
	}
	void SetAverage(int avg)
	{
		Average = avg;
	}

	// these are my getters I am defining them here since they are only one line of code.
	string GetFirstName() const { return firstName; }
	string GetLastName() const { return lastName; }
	string GetFullName() const { return fullName; }
	
	int GetID()const { return ID; }
	int GetQuiz1() const { return Quiz1; }
	int GetQuiz2() const { return Quiz2; }
	int GetTest1() const { return Test1; }
	int GetTest2() const { return Test2; }
	int GetAverage() const { return Average; }


private:
	string firstName;
	string lastName;
	string fullName;

	int ID = -1;
	int Quiz1 = 0;
	int Quiz2 = 0;
	int Test1 = 0;
	int Test2 = 0;
	int Average = 0;
};

// this class works off my first class of Students this helps keeps the code clean and stores the vector of all the students
class Students
{
public:
	void ReadData();
	void ReadGrades();

	double  FindAverage(int index);

	void classRoster() const;
	void classRosterGrade() const;
	void classRosterWeight() const;

private:
	vector<Student> AllStudents;
};

// since menu does not need to use the class it is of by it self :(
int menu();
