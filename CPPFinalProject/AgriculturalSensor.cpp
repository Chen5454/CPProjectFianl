#include "AgriculturalSensor.h"

AgriculturalSensor::AgriculturalSensor(const std::string& name)
	: temperature(0.0f), humidity(0.0f), soilMoisture(0.0f), lightIntensity(0.0f), cropName("") {
	sensorName = name;

	keyWords.push_back("Temp");
	keyWords.push_back("Hum");
	keyWords.push_back("Moist");
	keyWords.push_back("Light");
	keyWords.push_back("Crop");
}

void AgriculturalSensor::setTemperature(float temp)
{
	temperature = temp;
}

void AgriculturalSensor::setHumidity(float hum)
{
	humidity = hum;
}

void AgriculturalSensor::setSoilMoisture(float moisture)
{
	soilMoisture = moisture;
}

void AgriculturalSensor::setLightIntensity(float intensity)
{
	lightIntensity = intensity;
}

void AgriculturalSensor::setCropName(std::string crop)
{
	cropName = crop;
}

void AgriculturalSensor::setValWithKey(std::string keyWord, int intVal)
{
	if (keyWord == "Temp")
	{
		setTemperature(intVal);
	}
	else if (keyWord == "Hum")
	{
		setHumidity(intVal);
	}
	else if (keyWord == "Moist")
	{
		setSoilMoisture(intVal);
	}
	else if (keyWord == "Light")
	{
		setLightIntensity(intVal);
	}
}

void AgriculturalSensor::setValWithKey(std::string keyWord, std::string stringVal)
{
	if (keyWord == "Crop")
	{
		setCropName(stringVal);
	}
}

void AgriculturalSensor::setData(float temp, float hum, float moisture, float intensity, std::string crop)
{
	setTemperature(temp);
	setHumidity(hum);
	setSoilMoisture(moisture);
	setLightIntensity(intensity);
	setCropName(crop);
}

std::string AgriculturalSensor::getData()
{
	//SensorName(Agricultural Sensor):Temp(12.5):Hum(54):Moist(25.5):Light(12.8):Crop(Corn)
	//{
	//	"name": '"'CropA',
	//		"temperature" : 25.5,
	//		"humidity" : 70.2,
	//		"soil_moisture" : 45.8,
	//		"light_intensity" : 1200.0
	//}

	std::string dataString;

	dataString = "\n{\"Crop\" : \"" + cropName + "\" , \n";
	dataString += "\"Temperature\" : " + std::to_string(temperature) + " , \n";
	dataString += "\"Humidity\" : " + std::to_string(humidity) + " , \n";
	dataString += "\"Moisture\" : " + std::to_string(soilMoisture) + " , \n";
	dataString += "\"Light\" :" + std::to_string(lightIntensity) + "}";


	return dataString;
}

void AgriculturalSensor::inputReader()
{
}

void AgriculturalSensor::printData()
{
	std::cout << "Displaying Recent Data" << std::endl;
	std::cout << "Sensor: " << sensorName << std::endl;
	std::cout << "Temperature: " << temperature << "�C" << std::endl;
	std::cout << "Humidity: " << humidity << "%" << std::endl;
	std::cout << "Soil Moisture: " << soilMoisture << "%" << std::endl;
	std::cout << "Light Intensity: " << lightIntensity << " lux" << std::endl;
	std::cout << "Crop: " << cropName << std::endl;
}
