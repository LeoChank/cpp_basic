#include "random_game.h"

void init_random(unsigned int& max_value, unsigned int& random_value)
{
	std::srand(std::time(nullptr));
	random_value = std::rand() % max_value;
	std::cout << "Current hidden value in the range: " << "1 - " << max_value << std::endl;
	return;
}
