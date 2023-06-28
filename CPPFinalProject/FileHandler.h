#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Sensor.h"

class FileHandler {

public:
	FileHandler();
	void GetFile();
	void GetCommands();

private:
	std::fstream newFile;
	std::string NumTranslate(std::string input) const;
};