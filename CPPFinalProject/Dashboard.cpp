#include "Dashboard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Dashboard::parseData()
{
	std::ifstream file("JsonData.txt");

	if (file.is_open()) {
		crops.clear();

		Crop crop;
		std::string key;
		std::string valueString;
		bool isValue = false;
		bool isNegative = false;
		char currentChar;
		int level = 0;

		std::cout << "------------------------------\n";

		while (file.get(currentChar)) {
			switch (currentChar) {
			case '{':
			case '[':
				level++;
				break;
			case '}':
			case ']':
			case ',':
				if (!valueString.empty()) {
					if (key == "Crop") {
						crop.cropName = valueString;
					}
					else if (key == "Temperature") {
						crop.temperature = std::stof(valueString);
					}
					else if (key == "Humidity") {
						crop.humidity = std::stof(valueString);
					}
					else if (key == "Moisture") {
						crop.soilMoisture = std::stof(valueString);
					}
					else if (key == "Light") {
						crop.lightIntensity = std::stof(valueString);
					}
					key.clear();
					isValue = false;
					valueString.clear();
				}
				if (currentChar == '}' || currentChar == ']') {
					level--;
					if (level == 1) { // If we are at the top level, add crop to crops list
						crops.push_back(crop);
						crop = Crop(); // Clear the current crop 
					}
				}
				break;
			case '\"':
				// Read the key or value
				if (!isValue)
				{
					key.clear();
					while (file.get(currentChar) && currentChar != '\"') {
						key.push_back(currentChar);
					}
				}
				else
				{
					valueString.clear();
					while (file.get(currentChar) && currentChar != '\"') {
						valueString.push_back(currentChar);
					}
				}
				break;
			case ':':
				// value after ':'
				isValue = true;
				valueString.clear();
				break;
			case '-':
				// Negative sign 
				isNegative = true;
				valueString.push_back(currentChar);
				break;
			default:
				// Read a number value
				if (isdigit(currentChar) || currentChar == '.') {
					valueString.push_back(currentChar);
				}
				break;
			}
		}

		file.close();
		for (const auto& crop : crops) // Displaying the Data from the JSON to the CMD
		{
			std::cout << "Crop: " << crop.cropName << std::endl;
			std::cout << "Temperature: " << crop.temperature << "C" << std::endl;;
			std::cout << "Humidity: " << crop.humidity << "%" << std::endl;
			std::cout << "Soil Moisture: " << crop.soilMoisture << "%" << std::endl;
			std::cout << "Light Intensity: " << crop.lightIntensity << " lux" << std::endl;

			std::cout << std::endl;
		}
		if (crops.size() == 0)
		{
			std::cout << "Data List Is Empty!\n";
		}

		std::cout << "------------------------------\n";
	}
	else
	{
		std::cout << "Error: Failed to open file." << std::endl;
	}
}
