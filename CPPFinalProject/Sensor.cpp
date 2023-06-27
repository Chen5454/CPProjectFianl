#include <iostream>
#include <string>

class Sensor {
private:
    std::string sensorName;
    float temperature;
    float humidity;
    float soilMoisture;
    float lightIntensity;

public:
    Sensor(const std::string& name)
        : sensorName(name), temperature(0.0f), humidity(0.0f), soilMoisture(0.0f), lightIntensity(0.0f) {}

    void setTemperature(float temp) {
        temperature = temp;
    }

    void setHumidity(float hum) {
        humidity = hum;
    }

    void setSoilMoisture(float moisture) {
        soilMoisture = moisture;
    }

    void setLightIntensity(float intensity) {
        lightIntensity = intensity;
    }

    void printData() const {
        std::cout << "Sensor: " << sensorName << std::endl;
        std::cout << "Temperature: " << temperature << "°C" << std::endl;
        std::cout << "Humidity: " << humidity << "%" << std::endl;
        std::cout << "Soil Moisture: " << soilMoisture << "%" << std::endl;
        std::cout << "Light Intensity: " << lightIntensity << " lux" << std::endl;
    }
};