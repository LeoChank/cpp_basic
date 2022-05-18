#include <iostream>
#include <string>
#include "poly_calc.h"

int main(){
	std::cin >> input_str;

	calc_min calc_minimal;
	calc_max calc_maximal;
	calc_mean mean;

	polymorph_calculate(calc_minimal);
	polymorph_calculate(calc_maximal);
	polymorph_calculate(mean);
}

