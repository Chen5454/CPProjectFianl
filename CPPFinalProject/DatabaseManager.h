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
	void writeData(std::string data);
	void JsonAddSimpleData(std::string simpleData);
	void ClosedFile();
};