#include "pch.h"
#include "../2/FindAndReplace.h"

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
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
	std::string afterReplace;
	size_t position = 0;

	while (position < subject.length())
	{
		size_t found = subject.find(search, position);
		afterReplace.append(subject, position, found - position);
		position = found;
		if (position != std::string::npos)
		{
			afterReplace.append(replace);
			position += search.length();
		}
	}

	return afterReplace;
}