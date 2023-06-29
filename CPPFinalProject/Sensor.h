#pragma once
#include <iostream>
#include <string>
#include <vector>

class Sensor {
public:
	Sensor() { sensorName = "NewSensor"; };
	Sensor(const std::string& name) { sensorName = name; }
	std::string GetName() { return sensorName; }

protected:
	std::string sensorName;
	std::vector<std::string> keyWords;
};

