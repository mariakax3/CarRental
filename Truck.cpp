#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Truck.h"
#include "validation.h"

using namespace std;

Truck::Truck()
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
	volume = getInput(i_eg, "Volume [m^3]:");
	capacity = strtof(getInput(s_eg, "Capacity [t]:", "").c_str(), NULL);
	length = strtof(getInput(s_eg, "Length[m]:", "").c_str(), NULL);
	width = strtof(getInput(s_eg, "Width [m]:", "").c_str(), NULL);
	height = strtof(getInput(s_eg, "Height [m]:", "").c_str(), NULL);
	cost = getInput(i_eg, "Cost [PLN/24 h]:");

	temp = getInput(i_eg, "Availability [1 - YES/2 - NO]:", 1, 2, 40);
	switch (temp) {
		case 1: { availability = true; break; }
		case 2: { availability = false; break; }
	}
}

Truck::Truck(char * data[])
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
	volume = stoi(data[10]);
	capacity = strtof(data[11], NULL);
	length = strtof(data[12], NULL);
	width = strtof(data[13], NULL);
	height = strtof(data[14], NULL);
}

Truck::~Truck()
{
	delete this;
}

void Truck::showData(bool showWidthDetails)
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
	cout << left << "Capacity:";
	cout << this->getCapacity() << " t" << endl;

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
		cout << left << "Length:";
		cout << this->getLength() << " m" << endl;

		cout.width(30);
		cout << left << "Width:";
		cout << this->getWidth() << " m" << endl;

		cout.width(30);
		cout << left << "Height:";
		cout << this->getHeight() << " m" << endl;
	}

	cout.width(30);
	cout << left << "Cost:";
	cout << this->getCost() << " PLN/24 h" << endl;

	cout.width(30);
	cout << left << "Car available:";
	if (this->getAvailability()) { cout << "Yes" << endl; }
	else { cout << "No" << endl; };
}

void Truck::saveData(ofstream &file)
{
	file << "t;" << this->getBrand() << ";" << this->getModel() << ";" << this->getEnginePower() << ";" <<
		this->getEngineCapacity() << ";" << this->getFuelUsage() << ";" << this->getGearboxType() << ";" <<
		this->getMileage() << ";" << this->getCost() << ";" << this->getAvailability() << ";" << this->getVolume() <<
		";" << this->getCapacity() << ";" << this->getLength() << ";" << this->getWidth() << ";" <<
		this->getHeight() << endl;
}
