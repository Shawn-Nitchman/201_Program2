#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentClass.h"

using namespace std;

// this funtion is to make the menu output so it does not clutter my main
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

		// this is to check to make sure the user puts in an correct value
		if (choice < 0 || choice > 4)
		{
			cout << "Invalid choice please input either 1, 2, 3, or 4" << endl;
		}
		else
			break;
	}
	
	return choice;
}

// This function is to the data of the first file. Calls class of Students becuase that were my vector is
void Students::ReadData()
{
	// this now access the class of student where all the data is held
	Student currStudent;
	int SID;
	string last, first, fulNam;
	ifstream input;
	
	// opens the file of IDs and name
	input.open("INFO.txt");

	// This loops will go though the whole file putting the inputs were they need to go
	while (!input.eof())
	{
		// inputs from the file since id , first name and last name are in the same order 
		input >> SID >> first >> last;
		fulNam = last + ", " + first; // FIXME wants ful name as a an independt funtion.

		// this assigns each vairalbe with the inputs then ends with a push back to move onto another index of vector
		currStudent.SetID(SID);
		currStudent.SetFirstName(first);
		currStudent.SetLastName(last);
		currStudent.SetFullName(fulNam);
		AllStudents.push_back(currStudent);
	}

	// closes file since all the data has been read and input into the class
	input.close();
}

// this function is the data of the second file. Calls class of Students beucase that were my vector is
void Students::ReadGrades()
{
	// this now access the class of student where all the data is held
	Student currStudent;
	int SID, temp;
	int quiz1, quiz2, test1, test2;
	int i = 0;
	ifstream input;

	// opens the file that has the Id and grades
	input.open("Grades.txt");

	// this loop will go through the whole file
	while (!input.eof())
	{
		// reads the first line of input seperating them respectly
		input >> SID >> quiz1 >> quiz2 >> test1 >> test2;

		// Since the ID are all mixed up I need to match the correct ID to the correct Index of my vector.
		for (int j = 0; j < AllStudents.size(); ++j)
		{
			//this is going through my vector and getting the ID at the first index
			currStudent = AllStudents.at(j);
			temp = currStudent.GetID();
			
			// this checks to see if the first inex ID matchs with the ID i just got form the file 
			if (SID == temp)
			{
				// if it matchs it sets i which will be used out the the loop to assign the grade to the right student
				i = j;
				break;
			}
			// if the IDs did not match up it then goes through the loop again. once the correct ID is found it will break from the loop
		}

		// this is were it assing the grades to the correct ID for i that was gotten above. Since it is a vector it needs to be passed by reference
		Student& editStudent = AllStudents.at(i);
		editStudent.SetQuiz1(quiz1);
		editStudent.SetQuiz2(quiz2);
		editStudent.SetTest1(test1);
		editStudent.SetTest2(test2);
	}
	// clsoes the file since all the data has ben put into the class
	input.close();
}

// this function prints out the class roster with no grades it is a const becuase it should only output
void Students::classRoster() const
{
	Student currStudent;
	unsigned int i;

	// Using a loop to go thorugh each index of my vector
	for (i = 0; i < AllStudents.size(); ++i)
	{
		// I only need to output the ID and name so I only need to use the gets for thosue values
		currStudent = AllStudents.at(i);
		cout << currStudent.GetID() <<" " << currStudent.GetFullName() <<endl;
	
	}
}

// This function prints out the class roster with there grades is is a const becuase it should only output
void Students::classRosterGrade() const
{
	Student currStudent;
	unsigned int i;

	// using a loop to go thorugh each index of my vector
	for (i = 0; i < AllStudents.size(); ++i)
	{
		currStudent = AllStudents.at(i);
		// I need to output there Ids and grades since all there grades are a seperate variable i need to get each one. 
		cout << currStudent.GetFullName() << ": " << currStudent.GetQuiz1() << " " << currStudent.GetQuiz2() << " " << currStudent.GetTest1()<< " " <<currStudent.GetTest2() << endl;
	}
}

void Students::classRosterWeight() const
{
	Student currStudent;
	int i;
	double avg;

	for (i = 0; i < AllStudents.size(); ++i)
	{
		Student& editStudent = AllStudents.at(i);
		avg = FindAverage();
		currStudent = AllStudents.at(i);
		cout << "Weighted average score of " << currStudent.GetFullName() << " is       " << avg << " out of 100%" << endl;
	}
}

double Students::FindAverage(int index)
{
	Student currStudent;
	double quiz1, quiz2, test1, test2, finalGrade;
	const double quiz1Weight = 0.25, quiz2Weight = 0.25, test1Weight = 0.25, test2Weight = 0.50;

	currStudent = AllStudents.at(index);

	quiz1 = currStudent.GetQuiz1() * quiz1Weight;
	quiz2 = currStudent.GetQuiz2() * quiz2Weight;
	test1 = currStudent.GetTest1() * test1Weight;
	test2 = currStudent.GetTest2() * test2Weight;

	finalGrade = quiz1 + quiz2 + test1 + test2;
	return finalGrade;
}

