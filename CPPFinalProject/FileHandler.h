#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
//#include "Sensor.h"
#include "AgriculturalSensor.h"
#include "DatabaseManager.h"
#include "Dashboard.h"
class FileHandler {

public:
	FileHandler();
	void GetFile();
	void GetCommands();
	void AddCommand(std::string fullInput);
	void RegisterSensor(AgriculturalSensor* newSensor);
	void RegisterDashboard(Dashboard* newDashboard);
	void GetDatabase(DatabaseManager* database);
	void UserInput();

private:
	std::fstream newFile;
	std::vector<AgriculturalSensor*> registeredSensors;
	DatabaseManager* database_manager;
	Dashboard* dashboardPointer;

	std::string NumTranslate(std::string input) const;
	bool CheckIfNum(std::string input) const;
	bool CheckPercentage(std::string input) const;
	bool isInputing = true;
};