#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentClass.h"

using namespace std;

int main()
{
	int chooseApp;
	chooseApp = menu();


	Students School;

	School.InputStudents();

	while (chooseApp != 4)
	{
		if (chooseApp == 1)
		{
			School.print();
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
