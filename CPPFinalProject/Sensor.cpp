#include "Sensor.h"

Sensor::Sensor(const std::string& name)
	: sensorName(name), temperature(0.0f), humidity(0.0f), soilMoisture(0.0f), lightIntensity(0.0f), cropName("") {
	keyWords.push_back("Temp");
	keyWords.push_back("Hum");
	keyWords.push_back("Moist");
	keyWords.push_back("Light");
	keyWords.push_back("Crop");
}

void Sensor::setTemperature(float temp)
{
	temperature = temp;
}

void Sensor::setHumidity(float hum)
{
	humidity = hum;
}

void Sensor::setSoilMoisture(float moisture)
{
	soilMoisture = moisture;
}

void Sensor::setLightIntensity(float intensity)
{
	lightIntensity = intensity;
}

void Sensor::setCropName(std::string crop)
{
	cropName = crop;
}

void Sensor::setValWithKey(std::string keyWord, int intVal)
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

void Sensor::setValWithKey(std::string keyWord, std::string stringVal)
{
	if (keyWord == "Crop")
	{
		setCropName(stringVal);
	}
}

void Sensor::setData(float temp, float hum, float moisture, float intensity, std::string crop)
{
	setTemperature(temp);
	setHumidity(hum);
	setSoilMoisture(moisture);
	setLightIntensity(intensity);
	setCropName(crop);

}

void Sensor::inputReader()
{
}


