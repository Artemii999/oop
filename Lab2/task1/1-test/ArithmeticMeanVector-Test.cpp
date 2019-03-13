#include "pch.h"
#include "../1/ArithmeticMeanVector.h"
#include <algorithm>
#include <vector>

using namespace std;

bool IsEqually(const vector<double>& input, const vector<double>& output)
{
	return input == output;
}

TEST_CASE("input - empty vector, output - empty vector")
{
	vector<double> numbers = {};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {}));
}

TEST_CASE("Arithmetic Mean tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	REQUIRE(FindArithmeticMeanPositiveElements(testArray) == 1);
	testArray = { 0 };
	REQUIRE(FindArithmeticMeanPositiveElements(testArray) == 0);
}

TEST_CASE("Sum arithmetic mean to array - tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	double ArithmeticMean = 2.5;
	std::vector<double> etalonArray = { 3.5, 3.5, 3.5, 3.5, 3.5 };
	SumNumberToArrayElements(testArray, ArithmeticMean);
	REQUIRE(IsEqually(testArray, etalonArray) == true);
}

TEST_CASE("ProcessVector - tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	ProcessVector(testArray);
	std::vector<double> etalonArray = { 2, 2, 2, 2, 2 };
	REQUIRE(IsEqually(testArray, etalonArray) == true);
}

TEST_CASE("ProcessVector - empty vector- tests")
{
	std::vector<double> testArray = {};
	ProcessVector(testArray);
	std::vector<double> etalonArray = {};
	REQUIRE(IsEqually(testArray, etalonArray) == true);
}
