#include "DatabaseManager.h"


DatabaseManager::DatabaseManager()
{
	getFile();
}

void DatabaseManager::getFile()
{
	std::fstream FILE("JsonData.txt");
	dataFile.open("JsonData.txt",std::ios::out);
}

void DatabaseManager::writeData(std::string sensorName, std::string data)
{
	dataFile << data;
}

void DatabaseManager::JsonAddSimpleData(std::string simpleData)
{
	dataFile << simpleData;
}
	