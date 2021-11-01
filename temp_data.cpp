#include "temp_data.h"

#include <iomanip>
#include <iostream>

void print_temp_list(std::ostream& os, const std::vector<Temp_data>& data) {

	os << std::setprecision(2) << std::fixed;
	os << "   Date    Min Temp Max Temp\n"; // output stream of date & min/max temps
	os << "   ----    -------- --------\n"; // template for output format

	for (int i = 0; i < data.size(); i++)
	{
		os << std::setw(10) << std::setprecision(2) << data[i].date << " "
			<< std::setw(5) << std::setprecision(2) << data[i].min_temp << " "
			<< std::setw(5) << std::setprecision(2) << data[i].max_temp << "\n";
	}
}