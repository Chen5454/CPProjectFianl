#pragma once
#include <fstream>
#include <iostream>
#include <string>


class DatabaseManager
{

private:
	std::fstream dataFile;


public:

	DatabaseManager();
	void writeData(std::string data);
	void JsonAddSimpleData(std::string simpleData);
	void ClosedFile();
	void GetFile();

};