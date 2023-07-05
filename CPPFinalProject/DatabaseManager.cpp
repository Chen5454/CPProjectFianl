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

void DatabaseManager::writeData(std::string data)
{
	dataFile << data;
}

void DatabaseManager::JsonAddSimpleData(std::string simpleData)
{
	dataFile << simpleData;
}

void DatabaseManager::ClosedFile()
{
	dataFile.close();
	//std::cout << "Closed File" << std::endl;
}
	