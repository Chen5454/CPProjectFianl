#include <iostream>
#include "FileHandler.h"
#include "AgriculturalSensor.h"
using namespace std;

int main() {

	FileHandler fh;

	AgriculturalSensor ags("Agricultural Sensor");

	AgriculturalSensor* pAgs = &ags;

	fh.RegisterSensor(pAgs);

	fh.GetCommands();

	cout << endl;

	ags.printData();

	return 0;
}