#pragma once

#include <iostream>
#include "ColumnList.h"
#include "RowList.h"

class Table
{
	public:
		Table();
		Table(std::string name);
		Table(std::string name, ColumnList structure);
		std::string name;
		ColumnList structure;
		RowList data;
};

