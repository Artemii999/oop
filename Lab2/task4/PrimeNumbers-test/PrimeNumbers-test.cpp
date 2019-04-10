#include "pch.h"
#include "../PrimeNumbers/PrimeNumbersGenerator.h"

bool IsEqually(const std::set<int>& set1, const std::set<int>& set2)
{
	return set1 == set2;
}

TEST_CASE("test GetNumber - function convert string to int in range 1..10^8 and return bool value")
{
	int number = 0;
	std::string errorMsg;
	CHECK(GetNumber("", number, errorMsg) == false);
	CHECK(GetNumber("10000000000", number, errorMsg) == false);
	CHECK(GetNumber("100000000", number, errorMsg) == true);
	CHECK(number == 100000000);
	CHECK(GetNumber("number", number, errorMsg) == false);
}

TEST_CASE("test GeneratePrimeNumbersSet - function return set of prime numbers by lower input number")
{
	CHECK(IsEqually(GeneratePrimeNumbersSet(10), { 2, 3, 5, 7 }));
	CHECK(IsEqually(GeneratePrimeNumbersSet(2), { 2 }));
	CHECK(IsEqually(GeneratePrimeNumbersSet(1), {}));
}
