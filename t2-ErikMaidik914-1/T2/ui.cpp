#include<string>
#include <iostream>
#include"ui.h"
using namespace std;


void Ui::run()
{
	while (1)
	{
		cout << "WELCOME TO THE APP" << endl;
		cout << "CHOSE AN OPTION" << endl;
		cout << "1 - ADD A NEW CAR" << endl;
		cout << "2 - SHOW ALL CARS" << endl;
		int choice = getChoice();
		switch (choice) 
		{
			case 1:
				addCar();
				break;
			case 2:
				showAll();
				break;
			case 0:
				cout << "APPLICATION CLOSED!!";
				return;
		}

	}
}

int Ui::getChoice()
{
	int choice;
	cout << "your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}

void Ui::addCar()
{

}

void Ui::showAll()
{

}