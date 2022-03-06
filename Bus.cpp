#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Bus.h"
#include "validation.h"

using namespace std;

Bus::Bus()
{
	string s_eg = " ";
	int i_eg = 0;
	int temp;

	cout << "Enter the car data:" << endl;

	brand = getInput(s_eg, "Brand:", "@");
	model = getInput(s_eg, "Model:", "@");
	enginePower = getInput(i_eg, "Engine power [KM]:");
	engineCapacity = strtof(getInput(s_eg, "Engine capacity [dm^3]:", "").c_str(), NULL);
	fuelUsage = strtof(getInput(s_eg, "Fuel usage [l/100 km]:", "").c_str(), NULL);

	temp = getInput(i_eg, "Gearbox type [1 - MAN/2 - AUT]:", 1, 2, 40);
	switch (temp) {
		case 1: { gearboxType = "man"; break; }
		case 2: { gearboxType = "aut"; break; }
	}

	mileage = getInput(i_eg, "Mileage [km]:");
	numOfSeats = getInput(i_eg, "Number of seats:");
	volume = getInput(i_eg, "Volume [m^3]:");
	capacity = strtof(getInput(s_eg, "Capacity [t]:", "").c_str(), NULL);
	cost = getInput(i_eg, "Cost [PLN/24 h]:");

	temp = getInput(i_eg, "Availability [1 - YES/2 - NO]:", 1, 2, 40);
	switch (temp) {
		case 1: { availability = true; break; }
		case 2: { availability = false; break; }
	}
}

Bus::Bus(char * data[])
{
	brand = (string)data[1];
	model = (string)data[2];
	enginePower = stoi(data[3]);
	engineCapacity = strtof(data[4], NULL);
	fuelUsage = strtof(data[5], NULL);
	gearboxType = (string)data[6];
	mileage = stoi(data[7]);
	cost = stoi(data[8]);
	availability = stoi(data[9]);
	numOfSeats = stoi(data[10]);
	volume = stoi(data[11]);
	capacity = strtof(data[12], NULL);
}

Bus::~Bus()
{
	delete this;
}

void Bus::showData(bool showWidthDetails)
{
	cout.width(30);
	cout << left << "Brand:";
	cout << this->getBrand() << endl;

	cout.width(30);
	cout << left << "Model:";
	cout << this->getModel() << endl;

	cout.width(30);
	cout << left << "Engine power:";
	cout << this->getEnginePower() << " KM" << endl;

	cout.width(30);
	cout << left << "Engine capacity:";
	cout << setprecision(1) << fixed;
	cout << this->getEngineCapacity() << " dm^3" << endl;

	cout.width(30);
	cout << left << "Fuel usage:";
	cout << setprecision(1) << fixed;
	cout << this->getFuelUsage() << " l/100 km" << endl;

	cout.width(30);
	cout << left << "Number of seats:";
	cout << this->getNumOfSeats() << endl;

	if (showWidthDetails) {
		cout.width(30);
		cout << left << "Gearbox type:";
		cout << this->getGearboxType() << endl;

		cout.width(30);
		cout << left << "Mileage:";
		cout << this->getMileage() << " km" << endl;

		cout.width(30);
		cout << left << "Volume:";
		cout << this->getVolume() << " m^3" << endl;

		cout.width(30);
		cout << left << "Capacity:";
		cout << this->getCapacity() << " t" << endl;
	}

	cout.width(30);
	cout << left << "Cost:";
	cout << this->getCost() << " PLN/24 h" << endl;

	cout.width(30);
	cout << left << "Car available:";
	if (this->getAvailability()) { cout << "Yes" << endl; }
	else { cout << "No" << endl; };
}

void Bus::saveData(ofstream &file)
{
	file << "b;" << this->getBrand() << ";" << this->getModel() << ";" << this->getEnginePower() << ";" <<
		this->getEngineCapacity() << ";" << this->getFuelUsage() << ";" << this->getGearboxType() << ";" <<
		this->getMileage() << ";" << this->getCost() << ";" << this->getAvailability() << ";" <<
		this->getNumOfSeats() << ";" << this->getVolume() << ";" << this->getCapacity() << endl;
}
