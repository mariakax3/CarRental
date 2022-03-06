#pragma once
#include <fstream>
#include "Car.h"

class Bus : public Car
{
	int numOfSeats;
	int volume;
	float capacity;

public:
	Bus();
	Bus(char *data[]);
	~Bus();

	string getBrand() { return brand; };
	string getModel() { return model; };
	int getEnginePower() { return enginePower; };
	float getEngineCapacity() { return engineCapacity; };
	float getFuelUsage() { return fuelUsage; };
	string getGearboxType() { return gearboxType; };
	int getMileage() { return mileage; };
	int getCost() { return cost; };
	bool getAvailability() { return availability; };

	int getNumOfSeats() { return numOfSeats; };
	int getVolume() { return volume; };
	float getCapacity() { return capacity; };

	char getType() { return 'b'; };

	void setMileage(int i) { mileage = i; };
	void setCost(int i) { cost = i; };
	void setAvailability(bool b) { availability = b; };

	void showData(bool showWidthDetails);
	void saveData(ofstream &file);
};

