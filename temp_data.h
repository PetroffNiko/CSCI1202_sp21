#pragma once

#include <iosfwd>
#include <string>
#include <vector>

struct Temp_data
{
	std::string date;
	double min_temp;
	double max_temp;
};

void print_temp_list(std::ostream& os, const std::vector<Temp_data>& data);
