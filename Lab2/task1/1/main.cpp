// main.cpp: определяет точку входа для консольного приложения.
//

/*

*/
#include "pch.h"
using namespace std;

int main()
{
	cout << "Enter your array: \n";
	vector<double> numbers = ReadArray();
	ProcessVector(numbers);
	SortArray(numbers);
	PrintArray(numbers);
	return 0;
}
