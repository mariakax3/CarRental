#pragma once
#include <fstream>
#include <string>

using namespace std;

class Car
{
protected:
	string brand;
	string model;
	int enginePower;
	float engineCapacity;
	float fuelUsage;
	string gearboxType;
	int mileage;
	int cost;
	bool availability;

public:
	Car();
	virtual ~Car();
	virtual string getBrand() = 0;
	virtual string getModel() = 0;
	virtual int getEnginePower() = 0;
	virtual float getEngineCapacity() = 0;
	virtual float getFuelUsage() = 0;
	virtual string getGearboxType() = 0;
	virtual int getMileage() = 0;
	virtual int getCost() = 0;
	virtual bool getAvailability() = 0;

	virtual char getType() = 0;

	virtual void setMileage(int i) = 0;
	virtual void setCost(int i) = 0;
	virtual void setAvailability(bool b) = 0;

	virtual void showData(bool showWidthDetails) = 0;
	virtual void saveData(ofstream &file) = 0;
};

