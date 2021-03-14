#pragma once

#include <iostream>
#include "ColumnList.h"

class Table
{
	public:
		Table();
		Table(std::string name);
		Table(std::string name, ColumnList structure);
		std::string name;
		ColumnList structure;

};

