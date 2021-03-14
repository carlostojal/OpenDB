#pragma once

#include <iostream>

class Column
{
	public:
		Column();
		Column(std::string name, std::string value);
		std::string name;
		std::string value;
};

