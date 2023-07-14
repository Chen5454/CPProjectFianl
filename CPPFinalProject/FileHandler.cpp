#include "FileHandler.h"


FileHandler::FileHandler()
{
	GetFile();
}

void FileHandler::GetFile()
{
	//commandsFile.open("Commands.txt", std::ios::in | std::ios::out | std::ios::app);
	//if (!commandsFile.is_open())
	//	std::cerr << "Failed to open file: Commands.txt" << std::endl;

	if (!commandsFile.is_open())
		commandsFile.open("Commands.txt", std::ios::in | std::ios::out | std::ios::app);
}

// Gets the Commands from the Commands.txt
void FileHandler::GetCommands()
{
	GetFile();
	database_manager->GetFile();
	if (commandsFile.is_open()) {

		std::string input;
		database_manager->JsonAddSimpleData("[");
		while (std::getline(commandsFile, input))
		{
			bool gotKeyword = false;
			std::string tempKeyWord, tempValWord;
			AgriculturalSensor* currentSensor = nullptr;

			for (int i = 0; i < input.length(); i++)
			{

				if (input[i] == '?') // If a Line got this then it's a Comment and skips over it.
				{
					break;
				}

				if (input[i] == '(') // States that it got the Keyword and now will get the Value.
				{
					gotKeyword = true;
					continue;
				}
				else if (input[i] == ')') // Finished getting the Value.
				{
					for (int i = 0; i < registeredSensors.size(); i++)
					{
						if (tempValWord == registeredSensors[i]->GetName())
						{
							currentSensor = registeredSensors[i];
						}
					}
					continue;
				}
				else if (input[i] == ':') // Got Key & Value, Sets the info into the Sensor.
				{
					if (CheckIfNum(tempValWord))
					{
						currentSensor->setValWithKey(tempKeyWord, std::stof(tempValWord)); // Will set specific Data of CurrentSensor from the Key with passed Value.
					}
					else
					{
						currentSensor->setValWithKey(tempKeyWord, tempValWord); // Will set specific Data of CurrentSensor from the Key with passed Value.
					}

					gotKeyword = false;
					tempKeyWord = "";
					tempValWord = "";
					continue;
				}

				if (!gotKeyword)
				{
					tempKeyWord += input[i];
				}
				else
				{
					tempValWord += input[i];
				}

				if (i == input.length() - 2) // Reached EndOfLine, Got Key & Value, Sets the info into the Sensor.
				{
					if (CheckIfNum(tempValWord))
					{
						currentSensor->setValWithKey(tempKeyWord, std::stof(tempValWord)); // Will set specific Data of CurrentSensor from the Key with passed Value.
					}
					else
					{
						currentSensor->setValWithKey(tempKeyWord, tempValWord); // Will set specific Data of CurrentSensor from the Key with passed Value.
					}

					gotKeyword = false;
					tempKeyWord = "";
					tempValWord = "";
					continue;
				}

			}

			if (currentSensor != NULL)
			{
				// Writing the Command Input into the JSON DataBase
				database_manager->writeData(currentSensor->getData());
				if (!commandsFile.eof())
				{
					database_manager->JsonAddSimpleData(",\n");
				}
				else
				{
					database_manager->JsonAddSimpleData("\n");
				}
			}
		}
		database_manager->JsonAddSimpleData("]");
		database_manager->ClosedFile();
		commandsFile.close();
	}
}

// Adds Input from User as a Command into Commands.txt
void FileHandler::AddCommand(std::string fullInput)
{
	if (commandsFile.is_open())
	{
		commandsFile << "\n" << fullInput;
	}
}

void FileHandler::RegisterSensor(AgriculturalSensor* newSensor)
{
	registeredSensors.push_back(newSensor);
}

void FileHandler::RegisterDashboard(Dashboard* newDashboard)
{
	dashboardPointer = newDashboard;
}

void FileHandler::GetDatabase(DatabaseManager* database)
{
	database_manager = database;
}

void FileHandler::UserInput()
{
	while (isInputing)
	{
		std::cout << std::endl;
		std::cout << "1. Insert Sensor Data \n2. Display Data \n3. Quit Application\n";
		std::cout << "Pick An Operation (1/2/3): ";
		int answ;
		std::cin >> answ;
		std::cout << std::endl;

		if (answ == 1)
		{
			GetFile();
			bool isValid = true;
			std::string fullInput;
			std::string temperature;
			std::string humidity;
			std::string moisture;
			std::string light;
			std::string crop;


			std::cout << "Temperature(c): ";
			std::cin >> temperature;
			isValid = CheckIfNum(temperature) ? true : false;

			if (isValid)
			{
				std::cout << "Humidity(%): ";
				std::cin >> humidity;
				isValid = CheckIfNum(humidity) ? true : false;
				if (isValid)
				{
					isValid = CheckPercentage(humidity) ? true : false;
				}
			}
			if (isValid)
			{
				std::cout << "Moisture(%): ";
				std::cin >> moisture;
				isValid = CheckIfNum(moisture) ? true : false;
				if (isValid)
				{
					isValid = CheckPercentage(moisture) ? true : false;
				}
			}
			if (isValid)
			{
				std::cout << "Light(lux): ";
				std::cin >> light;
				isValid = CheckIfNum(light) ? true : false;
			}
			if (isValid)
			{
				std::cout << "Crop(name): ";
				std::cin >> crop;
				isValid = !CheckIfNum(crop) ? true : false;

			}

			if (isValid)
			{
				fullInput = "SensorName(Agricultural Sensor):Temp(" + temperature + "):Hum(" + humidity + "):Moist(" + moisture + "):Light(" + light + "):Crop(" + crop + ")";
				AddCommand(fullInput);
				std::cout << "Data Added Successfully! \n";
			}
			else
			{
				std::cout << "Invalid Input Try Again! \n";
			}
			commandsFile.close();
		}
		else if (answ == 2)
		{
			commandsFile.close();
			GetCommands();
			std::cout << std::endl;
			dashboardPointer->parseData();
		}
		else if (answ == 3)
		{
			commandsFile.close();
			isInputing = false;
		}
	}
}

std::string FileHandler::NumTranslate(std::string input) const
{
	std::string tempNum;
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			tempNum += int(input[i]);
		}
		else if (input[i] == '.' || input[i] == '-') {
			tempNum += input[i];
		}
	}
	return tempNum;
}

bool FileHandler::CheckIfNum(std::string input) const
{
	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
		{
			return false;
		}
	}
	return true;
}

bool FileHandler::CheckPercentage(std::string input) const
{
	std::string tempNum = NumTranslate(input);
	float tempNumF = std::stoi(tempNum);

	if (tempNumF >= 0 && tempNumF <= 100)
	{
		return true;
	}

	return false;
}
