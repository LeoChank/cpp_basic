#pragma once
#include <iostream>
std::string input_str;

class IStatistics {
public:

	virtual void calculate() const = 0;
};

class calc_min : public IStatistics {
public:
	calc_min() {}

	void calculate() const override {
		char min_val = input_str[0];
		for (int i = 1; i < input_str.size(); ++i)
		{
			if (min_val > input_str[i])
				min_val = input_str[i];
		}
		std::cout << "Minimal value is: " << std::atoi(static_cast<const char*>(&min_val)) << std::endl;
	}


};

class calc_max : public IStatistics {
public:
	calc_max() {}
	void calculate() const override {
		char max_val = input_str[0];
		for (int i = 1; i < input_str.size(); ++i)
		{
			if (max_val < input_str[i])
				max_val = input_str[i];
		}
		std::cout << "Maximal value is: " << std::atoi(static_cast<const char*>(&max_val)) << std::endl;
	}
};

class calc_mean : public IStatistics {
public:
	calc_mean() {}
	void calculate() const override {
		int sum = 0;
		for (int i = 0; i < input_str.size(); ++i)
		{
			char tmp = input_str[i];
			sum += std::atoi(static_cast<const char*>(&tmp));
		}
		std::cout << "Mean value is: " << (sum / input_str.size()) << std::endl;
	}

};

