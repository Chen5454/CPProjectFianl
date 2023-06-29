#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
//#include "Sensor.h"
#include "AgriculturalSensor.h"

class FileHandler {

public:
	FileHandler();
	void GetFile();
	void GetCommands();

	//void RegisterSensor(Sensor* newSensor);
	void RegisterSensor(AgriculturalSensor* newSensor);

private:
	std::fstream newFile;
	//std::vector<Sensor*> registeredSensors;
	std::vector<AgriculturalSensor*> registeredSensors;

	std::string NumTranslate(std::string input) const;
	bool CheckIfNum(std::string input) const;
};