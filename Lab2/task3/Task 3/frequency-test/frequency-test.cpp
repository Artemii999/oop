#include "pch.h"
#include "../../../../Catch2/catch.hpp"
#include "../frequency/frequency.h"
#include <locale>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool IsMapEqual(map<string, size_t> map1, map<string, size_t> map2)
{
	return map1 == map2;
}

bool IsStringEqual(string const& line1, string const& line2)
{
	return line1 == line2;
}

TEST_CASE("If add `hello` to testMap then testMap will be equal etalonMap")
{
	map<string, size_t> etalonMap = { { "hello", 1 } };
	string word = "hello";
	map<string, size_t> testMap;
	CountWordToStatistics(word, testMap);
	CHECK(IsMapEqual(testMap, etalonMap));
}

TEST_CASE("Different map are not equal to each other")
{
	map<string, size_t> map1 = { { "hello", 2 } };
	map<string, size_t> map2 = { { "Good", 2 } };
	CHECK(!IsMapEqual(map1, map2));
}

TEST_CASE("If add word `hello` again into the testMap then testMap will be like equal etalonMap")
{
	map<string, size_t> etalonMap = { { "hello", 2 } };
	string word = "hello";
	map<string, size_t> testMap;
	CountWordToStatistics(word, testMap);
	CountWordToStatistics(word, testMap);
	CHECK(IsMapEqual(testMap, etalonMap));
}

TEST_CASE("Words with different case are equal")
{
	string wordUpperCase = "HeLLo";
	string wordLowCase = "hello";
	StringToLowerCase(wordUpperCase);
	CHECK(IsStringEqual(wordLowCase, wordUpperCase));
}
