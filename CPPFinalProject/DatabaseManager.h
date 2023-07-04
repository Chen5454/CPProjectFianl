#pragma once
#include <fstream>
#include <iostream>
#include <string>


class DatabaseManager
{

private:
	std::fstream dataFile;

	void getFile();

public:

	DatabaseManager();
	void writeData(std::string sensorName,std::string data);
	void JsonOrganizer(bool isEnd);
};