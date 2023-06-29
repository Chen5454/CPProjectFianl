#pragma once
#include "Sensor.h"

class AgriculturalSensor : public Sensor {
private:
    std::string cropName;
    float temperature;
    float humidity;
    float soilMoisture;
    float lightIntensity;

public:
    AgriculturalSensor(const std::string& name);

    void setTemperature(float temp);

    void setHumidity(float hum);

    void setSoilMoisture(float moisture);

    void setLightIntensity(float intensity);

    void setCropName(std::string crop);

    void setValWithKey(std::string keyWord, int intVal);

    void setValWithKey(std::string keyWord, std::string stringVal);

    void setData(float temp, float hum, float moisture, float intensity, std::string crop);

    void inputReader();

    void printData();
};