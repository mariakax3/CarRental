//Author: Maria Karaszewska
//Date: 12-2021

#define DB_NAME "database.txt"
#define _WIN32_WINNT 0x0500

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "Car.h"
#include "PassengerCar.h"
#include "Truck.h"
#include "Bus.h"
#include "Fleet.h"
#include "validation.h"

using namespace std;

void drawLogo() {
	ifstream logo;
	string line;
	logo.open("logo.txt");
	while (getline(logo, line)) {
		cout << line << endl;
	}
	logo.close();
	cout << endl << endl << endl;
}

void clearAll() {
	system("cls");
	drawLogo();
}

void pressEnter() {
	cout << "Press Enter to continue..." << endl;
	_getch();
	clearAll();
}

void printDatabaseInfo(char t) {
	string text;
	switch (t) {
	case 'p': {text = "passenger cars."; break; }
	case 't': {text = "trucks."; break; }
	case 'b': {text = "buses."; break; }
	}
	cout << "The current database does not contain " << text << endl << endl;
}

char returnSelectedType() {
	int type = -1;

	cout << "[1] Passenger car" << endl;
	cout << "[2] Truck" << endl;
	cout << "[3] Bus" << endl;
	cout << "[0] Back to the menu" << endl;
	cout << "--------------------------------------" << endl << ">> ";

	getInput(type, "", 0, 3, 0);
	cout << endl;

	switch (type) {
		case 1: { return 'p'; }
		case 2: { return 't'; }
		case 3: { return 'b'; }
		case 0: { return '0'; }
	}
}

void showAll(Fleet *fleet) {
	if (fleet->fleetVector.size() == 0) {
		cout << "Currently our garage is empty." << endl << endl;
		return;
	}

	int i = 1, s = -1;
	bool details = false;

	cout.width(30);
	cout << left << "Would you like to see all details? [1 - YES/2 - NO]: " << endl << ">> ";
	s = getInput(s, "", 1, 2, 0);

	if (s == 1) { details = true; };

	for (auto & car : fleet->fleetVector) {
		cout << "---------------Car nr " << i << "---------------" << endl;
		car->showData(details);
		cout << endl;
		i++;
	}
}

void addCar(Fleet *fleet) {
	int type = -1;
	int i;
	float f;
	string s;

	cout << "Select type of a car:" << endl;
	cout << "[1] Passenger car" << endl;
	cout << "[2] Truck" << endl;
	cout << "[3] Bus" << endl;
	cout << "[0] Back to the menu" << endl;
	cout << "--------------------------------------------" << endl << ">> ";

	type = getInput(type, "", 0, 3, 0);
	cout << endl;
	
	switch (type) {
		case 1:
		{
			Car *car = new PassengerCar();
			fleet->fleetVector.push_back(car);
			break;
		}
		case 2:
		{
			Car *car = new Truck();
			fleet->fleetVector.push_back(car);
			break;
		}
		case 3:
		{
			Car *car = new Bus();
			fleet->fleetVector.push_back(car);
			break;
		}
		case 0:
		{
			return;
		}
	}

	cout << endl << "Car has been successfully added to the database." << endl << endl;
}

void updateInfo(Fleet *fleet) {
	if (fleet->fleetVector.size() == 0) {
		cout << "Currently our garage is empty." << endl << endl;
		return;
	}

	int i = 1, j = 1, num = -1, option = -1, data = -1, t = -1;
	bool b;

	cout << "Select the type of car to be updated:" << endl;
	
	t = returnSelectedType();

	if (t == '0') { return; };

	clearAll();

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else {
			cout << "------------------Car nr " << i << "------------------" << endl;
			car->showData(false);
			cout << endl;
			i++;
		}
	}

	if (i == 1) { printDatabaseInfo(t); return; };

	cout << "Select the car number to be updated:" << endl << ">> ";
	num = getInput(num, "", 1, i-1, 0);
	
	clearAll();
	
	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else if (j != num) { j++;  continue; }
		else {
			cout << "Selected car: " << car->getBrand() << " " << car->getModel() << endl << endl;

			cout << "Do you want to set new mileage? [1 - YES/2 - NO]:" << endl << ">> ";
			t = getInput(t, "", 1, 2, 0);
			cout << endl;
			if (t == 1) {
				cout << "Current mileage: " << car->getMileage() << " km" << endl << endl;
				cout << "Set new mileage [km]:" << endl;
				data = getInput(data, "");
				cout << endl;
				while (data < car->getMileage()) {
					cout << "The new mileage cannot be less than the previous one." << endl;
					data = getInput(data, "");
					cout << endl;
				};
				car->setMileage(data);
			}

			clearAll();
			cout << "Selected car: " << car->getBrand() << " " << car->getModel() << endl << endl;
			
			cout << "Do you want to set new cost? [1 - YES/2 - NO]:" << endl << ">> ";
			t = getInput(t, "", 1, 2, 0);
			cout << endl;
			if (t == 1) {
				cout << "Current cost: " << car->getCost() << " PLN/24 h" << endl << endl;
				cout << "Set new cost [PLN/24 h]:" << endl;
				data = getInput(data, "");
				car->setCost(data);
			}

			clearAll();
			cout << "Selected car: " << car->getBrand() << " " << car->getModel() << endl << endl;

			cout << "Do you want to set availability? [1 - YES/2 - NO]:" << endl << ">> ";
			t = getInput(t, "", 1, 2, 0);
			if (t == 1) {
				cout << endl << "Car available [1 - YES/2 - NO]:" << endl << ">> ";
				data = getInput(data, "", 1, 2, 0);
				switch (data) {
					case 1: { car->setAvailability(true); break; }
					case 2: { car->setAvailability(false); break; }
				}
			}
		}
	}

	cout << endl << "Database has been succesfully updated." << endl << endl;
}

void deleteCar(Fleet *fleet) {
	if (fleet->fleetVector.size() == 0) {
		cout << "Currently our garage is empty." << endl << endl;
		return;
	}

	int i = 1, j = 1, num = -1, count = 0, data = -1;
	char t;

	cout << "Select the type of car to be removed:" << endl;
	
	t = returnSelectedType();

	if (t == '0') { return; };

	clearAll();

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else {
			cout << "------------------Car nr " << i << "------------------" << endl;
			car->showData(false);
			cout << endl;
			i++;
		}
	}

	if (i == 1) { printDatabaseInfo(t); return; };

	cout << "Select the car number to be removed:" << endl << ">> ";
	num = getInput(num, "", 1, i - 1, 0);
	
	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { count++; continue; }
		else if (j != num) { j++; count++; continue; }
		else {
			cout << endl << "Selected car: " << car->getBrand() << " " << car->getModel() << endl << endl;
			cout << "Do you confirm your choice? [1 - YES/2 - NO]:" << endl << ">> ";
			data = getInput(data, "", 1, 2, 0);
			cout << endl;
			if (data == 1) {
				switch (data) {
					case 1:
					{
						fleet->fleetVector.erase(fleet->fleetVector.begin() + count);
						cout << endl << "Car has been succesfully removed from the database." << endl << endl;
						break;
					}
					case 2:
					{
						car->setAvailability(true);
						cout << endl << "The car removal has been successfully canceled." << endl << endl;
						break;
					}
				}
			}
			else {
				cout << endl << "The car removal has been successfully canceled." << endl << endl;
			}
			break;
			fleet->fleetVector.erase(fleet->fleetVector.begin() + count);
		}
	}
}

void rentCar(Fleet *fleet) {
	int i = 0, j = 1, num = -1, days = -1, data = -1;
	char t;

	cout << "Select the type of a rental car:" << endl;

	t = returnSelectedType();

	if (t == '0') { return; };

	clearAll();

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else if (car->getAvailability()) {
			i++;
			cout << "------------------Car nr " << i << "------------------" << endl;
			car->showData(true);
			cout << endl;
		}
	}

	if (i == 0) {
		cout << "Currently no cars available." << endl << endl;
		return;
	}

	cout << "Select the number of the rental car:" << endl << ">> ";
	num = getInput(num, "", 1, i, 0);

	cout << endl << "Enter the number of days you rent the car:" << endl;
	days = getInput(days, "");

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else if (car->getAvailability()) {
			if (j != num) { j++; continue; }
			else {
				clearAll();
				cout << "----------------Selected car----------------" << endl;
				car->showData(true);
				cout << endl << "Total cost: " << days * car->getCost() << " PLN" << endl << endl;
				cout << "Do you confirm your choice? [1 - YES/2 - NO]" << endl;

				data = getInput(data, "", 1, 2, 0);
				cout << endl;
				if (data == 1) {
					switch (data) {
						case 1: 
						{	
							car->setAvailability(false);
							cout << endl << "Car has ben successfully rented. Thank you." << endl << endl;
							break; 
						}
						case 2: 
						{ 
							car->setAvailability(true); 
							cout << endl << "The car rental has been successfully canceled." << endl << endl;
							break; 
						}
					}
				}
				else {
					cout << endl << "The car rental has been successfully canceled." << endl << endl;
				}
				break;
			}
		}
	}
}

void returnCar(Fleet *fleet) {
	int i = 0, j = 1, num = -1, data = -1;
	char t;

	cout << "Select the type of the returned car:" << endl;

	t = returnSelectedType();

	if (t == '0') { return; };

	clearAll();

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else if (!car->getAvailability()) {
			i++;
			cout << "------------------Car nr " << i << "------------------" << endl;
			car->showData(true);
			cout << endl;
		}
	}

	if (i == 0) {
		cout << "All cars have been returned." << endl << endl;
		return;
	}

	cout << "Select the number of the returned car:" << endl << ">> ";
	num = getInput(num, "", 1, i, 0);

	for (auto & car : fleet->fleetVector) {
		if (car->getType() != t) { continue; }
		else if (!car->getAvailability()) {
			if (j != num) { j++; continue; }
			else {
				clearAll();
				cout << "----------------Selected car----------------" << endl;
				car->showData(true);
				cout << endl << "Do you confirm your choice? [1 - YES/2 - NO]" << endl << ">> ";

				data = getInput(data, "", 1, 2, 0);
				cout << endl;
				if (data == 1) {
					car->setAvailability(true);
					cout << endl << "Car has ben successfully returned. Thank you." << endl << endl;
				}
				else {
					cout << endl << "The car rental has been successfully canceled." << endl << endl;
				}
				break;
			}
		}
	}
}

int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 972, 600, TRUE);
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	Fleet *fleet = new Fleet();
	fleet->readDatabase();
	drawLogo();

	int optMenu = -1;
	
	do {
		cout << "Choose one of available options:" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "[1] Show whole fleet" << endl;
		cout << "[2] Add new car to the fleet" << endl;
		cout << "[3] Update information about a car" << endl;
		cout << "[4] Remove a car from database" << endl;
		cout << "[5] Rent a car" << endl;
		cout << "[6] Return a car" << endl;
		cout << "[0] Quit" << endl;
		cout << "--------------------------------------------" << endl << ">> ";


		optMenu = getInput(optMenu, "", 0, 6, 0);

		switch (optMenu) {
			case 1:
			{
				clearAll();
				showAll(fleet);
				pressEnter();
				break;
			}
			case 2:
			{
				clearAll();
				addCar(fleet);
				pressEnter();
				break;
			}
			case 3:
			{
				clearAll();
				updateInfo(fleet);
				pressEnter();
				break;
			}
			case 4:
			{
				clearAll();
				deleteCar(fleet);
				pressEnter();
				break;
			}
			case 5:
			{
				clearAll();
				rentCar(fleet);
				pressEnter();
				break;
			}
			case 6:
			{
				clearAll();
				returnCar(fleet);
				pressEnter();
				break;
			}
			case 0:
			{
				cout << endl << "It was good to see you. Goodbye!" << endl;
				_getch();
				break;
			}
		}

	} while (optMenu != 0);

	fleet->saveDatabase();

	return 0;
}