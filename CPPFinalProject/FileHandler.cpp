#include "FileHandler.h"


FileHandler::FileHandler()
{
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

		while (std::getline(newFile,input))
		{

		}


		
		newFile.close();
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
		else if (input[i] == '.') {
			tempNum += input[i];
		}
	}
	return tempNum;
}
