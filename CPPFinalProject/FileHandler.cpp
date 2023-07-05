#include "FileHandler.h"


FileHandler::FileHandler()
{
	GetFile();
}

void FileHandler::GetFile()
{
	std::fstream FILE("Commands.txt");
	newFile.open("Commands.txt");
}

void FileHandler::GetCommands()
{
	if (newFile.is_open()) {

		std::string input;
		database_manager->JsonAddSimpleData("[");
		while (std::getline(newFile, input))
		{
			bool gotKeyword = false;
			std::string tempKeyWord, tempValWord;
			AgriculturalSensor* currentSensor = nullptr;

			for (int i = 0; i < input.length(); i++)
			{

				if (input[i] == '?')
				{
					break;
				}

				if (input[i] == '(')
				{
					gotKeyword = true;
					continue;
				}
				else if (input[i] == ')')
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
				else if (input[i] == ':')
				{
					if (CheckIfNum(tempValWord))
					{
						currentSensor->setValWithKey(tempKeyWord, std::stoi(tempValWord));
					}
					else
					{
						currentSensor->setValWithKey(tempKeyWord, tempValWord);
					}

					gotKeyword = false;
					//std::cout << tempKeyWord << " , " << tempValWord << std::endl;
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

				if (i == input.length() - 2)
				{
					if (CheckIfNum(tempValWord))
					{
						currentSensor->setValWithKey(tempKeyWord, std::stoi(tempValWord));
					}
					else
					{
						currentSensor->setValWithKey(tempKeyWord, tempValWord);
					}

					gotKeyword = false;
					//std::cout << tempKeyWord << " , " << tempValWord << std::endl << std::endl;
					tempKeyWord = "";
					tempValWord = "";
					continue;
				}

			}

			if(currentSensor!=NULL)
			{
				database_manager->writeData(currentSensor->getData());
				if (!newFile.eof())
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
		newFile.close();
	}
}

void FileHandler::RegisterSensor(AgriculturalSensor* newSensor)
{
	registeredSensors.push_back(newSensor);
}

void FileHandler::GetDatabase(DatabaseManager* database)
{
	database_manager = database;
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
