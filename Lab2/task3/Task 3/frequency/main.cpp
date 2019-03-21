#include "pch.h"
#include "frequency.h"

using namespace std;

int main()
{

	SetConsoleCP(866); // дл€ корректного ввода и вывода кирилицы
	SetConsoleOutputCP(866);

	string word;
	map<string, size_t> statisctic; // отсортированный ассоциативный контейнер, который содержит пары ключ-значение с неповтор€ющимис€ ключами.

	while (cin >> word)
	{
		StringToLowerCase(word);
		CountWordToStatistics(word, statisctic);
	}

	PrintFrequency(statisctic);
	return 0;
}
