#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentClass.h"

using namespace std;

int menu()
{
	int choice = 1;
	while (choice > 0 || choice < 5)
	{
		cout << " Welcome to the weighted averge application" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Please make a selection:" << endl;
		cout << "(1) Print class roster" << endl;
		cout << "(2) Print class roster with their grade" << endl;
		cout << "(3) Print class roster with students weighted total" << endl;
		cout << "(4) Exit" << endl;
		cout << "Enter your choice: ";

		cin >> choice;

		if (choice < 0 || choice > 5)
		{
			cout << "Invalid choice please input either 1, 2, 3, or 4" << endl;
		}
		else
			break;
	}
	
	return choice;
}

void Students::InputStudents()
{
	Student currStudent;
	int SID;
	string last, first;
	ifstream input;
	
	input.open("INFO.txt");

	while (!input.eof())
	{
		input >> SID >> first >> last;
		currStudent.SetID(SID);
		currStudent.SetFirstName(first);
		currStudent.SetLastName(last);
		AllStudents.push_back(currStudent);

	}

}
/*
void Student::ReadData()
{
	int temp;
	string first, last;
	ifstream input;
	vector<Student> SID;
	vector<Student> FName;
	vector<Student> LName;
	Student currStudent;

	input.open("INFO.txt");

	while (!input.eof())
	{
		input >> temp >> first >> last;
		currStudent.SetID(temp);
		currStudent.SetFirstName(first);
		currStudent.SetLastName(last);
		SID.push_back(currStudent);
		FName.push_back(currStudent);
		LName.push_back(currStudent);
	}
	
	input.close();

}
*/
void Student::SetID(int sNum)
{
	ID = sNum;
}

void Student::SetFirstName(string fName)
{
	firstName = fName;
}

void Student::SetLastName(string lName)
{
	lastName = lName;
}

void Students::print()
{
	Student currStudent;
	unsigned int i;

	for (i = 0; i < AllStudents.size(); ++i)
	{
		currStudent = AllStudents.at(i);
		cout << currStudent.GetID() <<endl;
	}
}

int Student::GetID()
{
	return ID;
}