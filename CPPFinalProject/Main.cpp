#include <iostream>
#include "FileHandler.h"
#include "AgriculturalSensor.h"
#include "DatabaseManager.h"
#include "Dashboard.h"
using namespace std;

int main() {

	FileHandler fh;

	AgriculturalSensor ags("Agricultural Sensor");

	AgriculturalSensor* pAgs = &ags;

	DatabaseManager dbm ;

	DatabaseManager* pdbm = &dbm;

	Dashboard dashboard;

	Dashboard* pDashboard = &dashboard;


	fh.GetDatabase(pdbm);

	fh.RegisterSensor(pAgs);

	fh.RegisterDashboard(pDashboard);

	fh.UserInput();

	//fh.GetCommands();

	//cout << endl;

	//dashboard.parseData();


	return 0;
}