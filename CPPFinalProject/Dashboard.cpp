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
    void parseData(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string str;
            char c;
            while (file.get(c)) {
                str += c;
            }

            file.close();

            size_t cropsStart = str.find("crops");
            if (cropsStart != std::string::npos) {
                size_t cropsArrayStart = str.find('[', cropsStart);
                size_t cropsArrayEnd = str.find(']', cropsStart);
                if (cropsArrayStart != std::string::npos && cropsArrayEnd != std::string::npos) {
                    std::string cropsData = str.substr(cropsArrayStart, cropsArrayEnd - cropsArrayStart + 1);

                    size_t cropStart = cropsData.find('{');
                    while (cropStart != std::string::npos) {
                        size_t cropEnd = cropsData.find('}', cropStart);
                        if (cropEnd != std::string::npos) {
                            std::string cropData = cropsData.substr(cropStart, cropEnd - cropStart + 1);
                            Crop crop;

                            size_t nameStart = cropData.find("name");
                            if (nameStart != std::string::npos) {
                                size_t nameValueStart = cropData.find(':', nameStart);
                                size_t nameValueEnd = cropData.find('\'', nameValueStart + 1);
                                if (nameValueStart != std::string::npos && nameValueEnd != std::string::npos) {
                                    crop.name = cropData.substr(nameValueStart + 1, nameValueEnd - nameValueStart - 1);
                                }
                            }

                            size_t temperatureStart = cropData.find("temperature");
                            if (temperatureStart != std::string::npos) {
                                size_t temperatureValueStart = cropData.find(':', temperatureStart);
                                if (temperatureValueStart != std::string::npos) {
                                    crop.temperature = std::stof(cropData.substr(temperatureValueStart + 1));
                                }
                            }

                            size_t humidityStart = cropData.find("humidity");
                            if (humidityStart != std::string::npos) {
                                size_t humidityValueStart = cropData.find(':', humidityStart);
                                if (humidityValueStart != std::string::npos) {
                                    crop.humidity = std::stof(cropData.substr(humidityValueStart + 1));
                                }
                            }

                            size_t soilMoistureStart = cropData.find("soil_moisture");
                            if (soilMoistureStart != std::string::npos) {
                                size_t soilMoistureValueStart = cropData.find(':', soilMoistureStart);
                                if (soilMoistureValueStart != std::string::npos) {
                                    crop.soilMoisture = std::stof(cropData.substr(soilMoistureValueStart + 1));
                                }
                            }

                            size_t lightIntensityStart = cropData.find("light_intensity");
                            if (lightIntensityStart != std::string::npos) {
                                size_t lightIntensityValueStart = cropData.find(':', lightIntensityStart);
                                if (lightIntensityValueStart != std::string::npos) {
                                    crop.lightIntensity = std::stof(cropData.substr(lightIntensityValueStart + 1));
                                }
                            }

                            crops.push_back(crop);
                            cropStart = cropsData.find('{', cropEnd);
                        }
                        else {
                            cropStart = std::string::npos;
                        }
                    }
                }
            }
        }
        else {
            std::cout << "Error: Failed to open file." << std::endl;
        }
    }
};