#include "pch.h"
#include "ArithmeticMeanVector.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<double> ReadArray()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	return numbers;
}

void SortArray(vector<double>& data)
{
	sort(data.begin(), data.end());
}

void PrintArray(const vector<double>& printArray)
{
	copy(printArray.begin(), printArray.end(), ostream_iterator<double>(cout, " "));
	cout << "\n";
}

double FindArithmeticMeanPositiveElements(const vector<double>& searchArray)
{
	double arithmeticMean = 0;
	size_t count = 0;
	for (double item : searchArray)
	{
		if (item >= 0)
		{
			arithmeticMean += item;
			count++;
		}
	}
	if (count != 0)
	{
		return (arithmeticMean / count);
	}
}

void SumNumberToArrayElements(vector<double>& arr, double number)
{
	transform(arr.begin(), arr.end(), arr.begin(), [=](double element) { return element += number; });
}

void ProcessVector(vector<double>& inArray)
{
	double arithmeticMean = FindArithmeticMeanPositiveElements(inArray);
	SumNumberToArrayElements(inArray, arithmeticMean);
}