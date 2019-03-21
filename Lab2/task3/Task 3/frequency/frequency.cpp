#include "pch.h"
#include "frequency.h"
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

void CountWordToStatistics(string const& word, map<string, size_t>& statistic)
{
	++statistic[word];
}

void PrintFrequency(map<string, size_t> const& statisctic)
{
	for (auto item = statisctic.begin(); item != statisctic.end(); item++)
	{
		cout << item->first << " -> " << item->second << "\n";
	}
}

void StringToLowerCase(string& line)
{
	transform(line.begin(), line.end(), line.begin(), tolower); //Применяет заданную функцию к одному диапазону и сохраняет результат в другой диапазон, начинающийся с d_first.
}