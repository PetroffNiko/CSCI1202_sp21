#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "split.h"
#include "temp_data.h"

int main(int argc, char* argv[])
{
	std::ifstream in_file{ "Temps.dat" };
	if (!in_file)
	{
		std::cout << "Could not open input file.\n";
		return EXIT_FAILURE;
	}

	std::vector<Temp_data> data;
	std::string line;
	if (!std::getline(in_file, line))
	{
		std::cout << "Could not reader header line.\n";
		return EXIT_FAILURE;
	}

	while (std::getline(in_file, line))
	{
		std::vector<std::string> fields = split(line, '"');
		std::string date = fields[1];
		double max_temp = atof(fields[3].c_str());
		double min_temp = atof(fields[5].c_str());
		data.push_back({ date, min_temp, max_temp });
	}

	if (argc == 1)
	{
		print_temp_list(std::cout, data);
	}
	else
	{
		std::ofstream out_file{ argv[1] };
		print_temp_list(out_file, data);
	}
}
