#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentClass.h"

using namespace std;

// main fuction that uses a menu to go through options
int main()
{
	int chooseApp;
	Students School;

	cout << " Welcome to the weighted averge application" << endl;
	cout << "-----------------------------------------------------" << endl;

	// I am reading the files here to me it makes more sense to read the files first so I can save them in the class
	School.ReadData();
	School.ReadGrades();

	// this now goes to the menu function that outputs the menu 
	chooseApp = menu();

	//keep going through the menu until the user enter in 4
	while (chooseApp != 4)
	{
		// use if statements to go into there repected option
		if (chooseApp == 1)
		{
			School.classRoster();
		}
		else if (chooseApp == 2)
		{
			School.classRosterGrade();
		}
		else if (chooseApp == 3)
		{
			// calling find averge since it only needs to be calulated if the user enters in 3
			School.FindAverage();
			School.classRosterWeight();
		}
		// will now ask the user again what they want to do
		chooseApp = menu();
	}
	

	cout << "Thank you for using the weighted average application";

	return 0;
}
