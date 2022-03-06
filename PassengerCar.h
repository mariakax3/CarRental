#pragma once
#include <fstream>
#include "Car.h"

using namespace std;

class PassengerCar : public Car
{
	int productionDate;
	string bodyType;
	int numOfPassengers;
	int numOfDoors;

	int tempX;

public:
	PassengerCar();
	PassengerCar(char *data[]);
	~PassengerCar();

	string getBrand() { return brand; };
	string getModel() { return model; };
	int getEnginePower() { return enginePower; };
	float getEngineCapacity() { return engineCapacity; };
	float getFuelUsage() { return fuelUsage; };
	string getGearboxType() { return gearboxType; };
	int getMileage() { return mileage; };
	int getCost() { return cost; };
	bool getAvailability() { return availability; };

	int getProductionDate() { return productionDate; };
	string getBodyType() { return bodyType; };
	int getNumOfPassengers() { return numOfPassengers; };
	int getNumOfDoors() { return numOfDoors; };

	char getType() { return 'p'; };

	void setMileage(int i) { mileage = i; };
	void setCost(int i) { cost = i; };
	void setAvailability(bool b) { availability = b; };

	void showData(bool showWidthDetails);
	void saveData(ofstream &file);
};

