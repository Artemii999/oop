#include "pch.h"
#include "Car.h"
#include "DriveCar.h"

int main()
{
	CCar car;
	CDriveCar driveCar(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!driveCar.ExecuteCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
}
