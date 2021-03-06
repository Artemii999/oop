﻿#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

uint8_t FlipByte(uint8_t byte) // uint8_t - Целый тип фиксированного размера (с положительным знаком) равный 8 битам
{
	uint8_t outputByte = 0;
	uint8_t inputByte = byte; // 1 байт = 8 бит

	for (int i = 0; i < 8; i++)
	{
		outputByte <<= 1; // Побитовый сдвиг влево, совмещённый с присваиванием
		outputByte |= inputByte & 0x01; //  & - побитовое И; 0x01 1 в 16 ричной системе; | - Побитовое ИЛИ 
		inputByte >>= 1; // Побитовый сдвиг вправо, совмещённый с присваиванием
	}

	return outputByte;
}

bool ParseCommandLine(int count, char* argv[], uint8_t& byte)
{
	if (count != 2)
	{
		cout << "invalid argument count\n"
			 << "usage: flipbyte.exe <byte>";
		return false;
	}
	int number = stoi(argv[1]);
	if (number < 0 || number > 255)
	{
		cout << "Input number is not in byte range.\n";
		return false;
	}
	byte = static_cast<uint8_t>(number);
	return true;
}

int main(int argc, char* argv[])
{
	try // try (пытаться) - начало блока исключений;
	{
		uint8_t byte;
		if (!ParseCommandLine(argc, argv, byte))
		{
			return 1;
		}
		cout << static_cast<int>(FlipByte(static_cast<uint8_t>(byte))) << "\n"; // static_cast - преобразует один статический тип, в другой
	}
	catch (const std::exception& e) // catch - начало блока, "ловящего" исключение;
	{
		cout << "!Error:" << e.what() << "!\n"; // what - Получить исключение идентификации строки
		return 1;
	}

	return 0;
}
