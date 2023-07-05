#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
//#include "Sensor.h"
#include "AgriculturalSensor.h"
#include "DatabaseManager.h"
class FileHandler {

public:
	FileHandler();
	void GetFile();
	void GetCommands();
	void RegisterSensor(AgriculturalSensor* newSensor);
	void GetDatabase(DatabaseManager* database);

private:
	std::fstream newFile;
	std::vector<AgriculturalSensor*> registeredSensors;
	DatabaseManager* database_manager;

	std::string NumTranslate(std::string input) const;
	bool CheckIfNum(std::string input) const;
};