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

void Students::ReadData()
{
	Student currStudent;
	int SID;
	string last, first, fulNam;
	ifstream input;
	
	input.open("INFO.txt");

	while (!input.eof())
	{
		input >> SID >> first >> last;
		fulNam = last + ", " + first;

		currStudent.SetID(SID);
		currStudent.SetFirstName(first);
		currStudent.SetLastName(last);
		currStudent.SetFullName(fulNam);
		AllStudents.push_back(currStudent);
	}

	input.close();
}

void Students::classRoster() const
{
	Student currStudent;
	unsigned int i;

	for (i = 0; i < AllStudents.size(); ++i)
	{
		currStudent = AllStudents.at(i);
		cout << currStudent.GetID() <<" " << currStudent.GetFullName() <<endl;
	
	}
}


