#pragma once
#include <fstream>
#include "Car.h"

class Truck : public Car
{
	int volume;
	float capacity;
	float length;
	float width;
	float height;

public:
	Truck();
	Truck(char *data[]);
	~Truck();

	string getBrand() { return brand; };
	string getModel() { return model; };
	int getEnginePower() { return enginePower; };
	float getEngineCapacity() { return engineCapacity; };
	float getFuelUsage() { return fuelUsage; };
	string getGearboxType() { return gearboxType; };
	int getMileage() { return mileage; };
	int getCost() { return cost; };
	bool getAvailability() { return availability; };

	int getVolume() { return volume; };
	float getCapacity() { return capacity; };
	float getLength() { return length; };
	float getWidth() { return width; };
	float getHeight() { return height; };

	char getType() { return 't'; };

	void setMileage(int i) { mileage = i; };
	void setCost(int i) { cost = i; };
	void setAvailability(bool b) { availability = b; };

	void showData(bool showWidthDetails);
	void saveData(ofstream &file);
};

