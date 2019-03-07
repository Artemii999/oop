#include "pch.h"

using namespace std;

bool CheckArgumentCount(int argc)
{
	if (argc != 3)
	{
		cout << "Not enough (or too many) input parameters. Example: task1_findText.exe input.txt hello \n";
		return false;
	}
	return true;
}

bool PrintLineNumbersContainingText(const string& fileName, const string& textToSearch)
{
	bool wasFound = false;
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		return false;
	}
	string line;
	size_t lineNumber = 1;
	while (getline(file, line))
	{
		size_t position = line.find(textToSearch);

		if (position != string::npos)
		{
			cout << lineNumber << "\n";
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

	string fileName = argv[1];
	string textToSearch = argv[2];

	if (!PrintLineNumbersContainingText(fileName, textToSearch))
	{
		cout << "Text not found\n";
		return 1;
	}

	return 0;
}
