#pragma once
#include "pch.h"
#include <map>
#include <string>

void CountWordToStatistics(std::string const& word, std::map<std::string, size_t>& statistic);

void PrintFrequency(std::map<std::string, size_t> const& statisctic);

void StringToLowerCase(std::string& line);