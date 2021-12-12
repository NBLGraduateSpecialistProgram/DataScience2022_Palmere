/* Header File for 9-manip.cpp */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector< std::vector<float> > readlines(const std::string& fn){
	std::ifstream in(fn);
	if (!in){ printf("Error: Could not access file."); exit(1); }
	std::string l;
	std::string d = " ";
	std::vector< std::vector<float> > data;
	while (std::getline(in, l)){
		std::vector<float> row;
		std::string x_str = l.substr(0, l.find(d));
		std::string y_str = l.erase(0, l.find(d) + d.length());
		row.push_back(atof(x_str.c_str()));
		row.push_back(atof(y_str.c_str()));
		data.push_back(row);
		row.clear();
	}
	return data;
}

