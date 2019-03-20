#include "pch.h"
#include "frequency.h"

using namespace std;

int main()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	string word;
	map<string, size_t> statisctic;

	while (cin >> word)
	{
		StringToLowerCase(word);
		CountWordToStatistics(word, statisctic);
	}

	PrintFrequency(statisctic);
	return 0;
}
