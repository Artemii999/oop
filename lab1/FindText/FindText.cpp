// task1_findText.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"

bool CheckArgumentCount(int argc)
{
	if (argc != 3)
	{
		std::cout << "Not enough (or too many) input parameters. Example: task1_findText.exe input.txt hello \n";
		return false;
	}
	return true;
}

bool PrintLineNumbersContainingText(const std::string& fileName, const std::string& textToSearch)
{
	bool wasFound = false;
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		return false;
	}
	std::string line;
	size_t lineNumber = 1;
	while (std::getline(file, line))
	{
		size_t position = line.find(textToSearch);

		if (position != std::string::npos)
		{
			std::cout << lineNumber << "\n";
			wasFound = true;
		}
		lineNumber++;
	}

	return wasFound;
}

int main(int argc, char* argv[])
{
	if (!CheckArgumentCount(argc))
	{
		return 1;
	}

	std::string fileName = argv[1];
	std::string textToSearch = argv[2];

	if (!PrintLineNumbersContainingText(fileName, textToSearch))
	{
		std::cout << "Text not found\n";
		return 1;
	}

	return 0;
}
