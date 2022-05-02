#include "file.h"

int read_write_file(const std::string& filename, const std::string& user_name, unsigned int attempts)
{
	std::ifstream in_file{ filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return -1;
	}
	std::cout << "\n\tHigh scores table:" << std::endl;
	
	std::string input_username;
	std::ofstream out_file;
	int high_score = 0;
	std::string line;
	unsigned int record = 0;
	HANDLE handle_stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		// Read the username first
		in_file >> input_username;
		if (input_username == user_name)
		{
			std::streampos pos = in_file.tellg();
			in_file >> record;
			
			out_file.open(filename, std::ios_base::binary | std::ios_base::in);
			if (!out_file.is_open()) {
				std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
				return -1;
			}

			// Append new results to the table:

			if (attempts < record)
			{
				Beep(500, 500);
				out_file.seekp(pos, out_file.beg);
				out_file.seekp(1, out_file.cur);
				if (attempts < 10)
				{
					out_file << static_cast<char>(0x30);
				}
				out_file << attempts;
				SetConsoleTextAttribute(handle_stdOut, FOREGROUND_GREEN);

				std::cout << "Congratulations! You have set a new record!" << std::endl;
			}
			out_file.close();
			break;
		}
		// if not find player name
		if (in_file.eof())
		{
			out_file.open(filename, std::ios_base::app);
			if (!out_file.is_open()) {
				std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
				return -1;
			}
			// Append new results to the table:
			//out_file << user_name << ' ';
			if (attempts < 10)
				out_file << "\n" << user_name + " " << static_cast<char>(0x30) << static_cast<char>(attempts + '0');
			else
				out_file << "\n" << user_name + " " << attempts;

			out_file.close();
			break;
		}
		// Read the high score next
		//in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}
	}
	SetConsoleTextAttribute(handle_stdOut, FOREGROUND_RED | FOREGROUND_BLUE);
	std::cout << "<-------------------------------------------------------->" << std::endl;
	std::cout << user_name << '\t' << "Best result: " << record << std::endl;
	std::cout << "Current result: " << attempts << std::endl;
	in_file.close();
	//break;
}
