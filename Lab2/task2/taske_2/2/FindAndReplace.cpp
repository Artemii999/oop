#include "pch.h"
#include "../2/FindAndReplace.h"

using namespace std;

string FindAndReplace(string const& subject, string const& search, string const& replace)
{
	/*
		subject - изначальная строка
		replace - на что заменяем
		search - что ищем
	*/
	if (search.empty() || subject.empty())
	{
		return subject;
	}
	string afterReplace;
	size_t position = 0;

	while (position < subject.length())
	{
		size_t found = subject.find(search, position); // поиск значения в диапазоне
		afterReplace.append(subject, position, found - position);
		position = found;
		if (position != string::npos)
		{
			afterReplace.append(replace);
			position += search.length();
		}
	}

	return afterReplace;
}