#pragma once
#include <vector>
#include "Car.h"

using namespace std;

class Fleet
{
public:
	vector<Car*> fleetVector;

	Fleet();
	~Fleet();
	void readDatabase();
	void saveDatabase();
};

