#pragma once
#include <iostream>
#include <string>
#include <vector>

class Sensor {
private:
    std::string sensorName;
    std::string cropName;
    float temperature;
    float humidity;
    float soilMoisture;
    float lightIntensity;
    std::vector<std::string> keyWords;


public:
   

    Sensor(const std::string& name);
       
    void setTemperature(float temp);

    void setHumidity(float hum);

    void setSoilMoisture(float moisture);

    void setLightIntensity(float intensity);

    void setCropName(std::string crop);

    void setValWithKey(std::string keyWord, int intVal);

    void setValWithKey(std::string keyWord, std::string stringVal);

    void setData(float temp, float hum, float moisture, float intensity,std::string crop);

    void inputReader();

    void printData() {
        std::cout << "Sensor: " << sensorName << std::endl;
        std::cout << "Temperature: " << temperature << "°C" << std::endl;
        std::cout << "Humidity: " << humidity << "%" << std::endl;
        std::cout << "Soil Moisture: " << soilMoisture << "%" << std::endl;
        std::cout << "Light Intensity: " << lightIntensity << " lux" << std::endl;
    }
};

