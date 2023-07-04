#include <iostream>
#include "FileHandler.h"
#include "AgriculturalSensor.h"
#include "DatabaseManager.h"
using namespace std;

int main() {

	FileHandler fh;

	AgriculturalSensor ags("Agricultural Sensor");

	AgriculturalSensor* pAgs = &ags;

	DatabaseManager dbm ;

	DatabaseManager* pdbm = &dbm;

	fh.GetDatabase(pdbm);

	fh.RegisterSensor(pAgs);

	fh.GetCommands();

	cout << endl;

	ags.printData();

	return 0;
}