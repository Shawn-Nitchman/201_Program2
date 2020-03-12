#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentClass.h"

using namespace std;

int main()
{
	int chooseApp;
	Students School;

	cout << " Welcome to the weighted averge application" << endl;
	cout << "-----------------------------------------------------" << endl;

	School.ReadData();
	chooseApp = menu();

	while (chooseApp != 4)
	{
		if (chooseApp == 1)
		{
			School.classRoster();
		}
		else if (chooseApp == 2)
		{
			//classRosterGrade();
		}
		else if (chooseApp == 3)
		{
			//classRosterWeight();
		}

		chooseApp = menu();
	}
	

	cout << "Thank you for using the weighted average application";

	return 0;
}
