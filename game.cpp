#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "file.h"
#include "random_game.h"

int main(int argc, char* argv[])
{
	const std::string filename = "scores.txt";
	std::string user_name;
	unsigned int random_value = 0;
	unsigned int max_value = 9;
	int buffer_value = 0;
	unsigned int attempts = 1;

	// Command line Arguments
	if (argc == 3)
	{
		if (argv[1] == static_cast<std::string>("-max"))
		{
			unsigned int value = std::stoi(argv[2]);
			if (value <= 99 && value > 0)
			{
				max_value = value;
			}
		}
		if (argv[1] == static_cast<std::string>("-level"))
		{
			unsigned int value = std::stoi(argv[2]);
			if (value == 1)
				max_value = 9;
			else if (value == 2)
				max_value = 19;
			else
				max_value = 49;
		}
	}
	else if (argc > 3)
	{
		std::cout << "Invalid arguments" << std::endl;
		return -1;
	}

	std::cout << "Hello! Enter your nickname: " << std::endl;
	std::cin >> user_name;

	std::cout << "Enter your guess, " << user_name << "!" << std::endl;
	init_random(max_value, random_value);
	while (true)
	{
		std::cin >> buffer_value;
		if (buffer_value < random_value)
			std::cout << "Greater than " << buffer_value << std::endl;
		else if (buffer_value > random_value)
			std::cout << "Less than " << buffer_value << std::endl;
		else
		{
			std::cout << "Correct! Good work!" << std::endl;
			read_write_file(filename, user_name, attempts);
			break;
		}
		++attempts;
	}
	return 0;
}