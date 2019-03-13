// Task2.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Wrong count arguments. Example ";
		return 1;
	}
	string subject;
	while (getline(cin, subject))
	{
		cout << FindAndReplace(subject, argv[1], argv[2]) << "\n";
	}
	return 0;
}
