#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

int read_write_file(const std::string& filename, const std::string& user_name, unsigned int attempts);

