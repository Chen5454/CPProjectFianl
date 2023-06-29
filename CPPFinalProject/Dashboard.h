#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Dashboard {
private:
    struct Crop {
        std::string name;
        float temperature;
        float humidity;
        float soilMoisture;
        float lightIntensity;
    };

    std::vector<Crop> crops;

public:
    void parseData(const std::string& filename);
};
