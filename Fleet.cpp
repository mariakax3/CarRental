#define DB_NAME "database.txt"
#define PARAMS 15

#include <fstream>
#include <string>
#include <string.h>
#include "Fleet.h"
#include "Car.h"
#include "PassengerCar.h"
#include "Truck.h"
#include "Bus.h"


Fleet::Fleet()
{
}

Fleet::~Fleet()
{
}

void Fleet::readDatabase()
{
	ifstream db;
	string line;
	char *spl;
	db.open(DB_NAME);
	while (getline(db, line)) {
		int i = 0;
		char *linec = new char[line.size() + 1];
		copy(line.begin(), line.end(), linec);
		spl = strtok(linec, ";");
		char *data[PARAMS] = { 0 };
		while (spl != NULL) {
			data[i] = spl;
			spl = strtok(NULL, ";");
			i++;
		}
		
		if (!strcmp(data[0], "p")) { Car *car = new PassengerCar(data); fleetVector.push_back(car); }
		else if (!strcmp(data[0], "t")) { Car *car = new Truck(data); fleetVector.push_back(car); }
		else if (!strcmp(data[0], "b")) { Car *car = new Bus(data); fleetVector.push_back(car); };
		
		delete[] linec;
	}
	db.close();
}

void Fleet::saveDatabase()
{
	ofstream db;
	db.open(DB_NAME);
	for (auto & car : this->fleetVector) {
		car->saveData(db);
	}
	db.close();
}
