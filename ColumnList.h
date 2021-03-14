#pragma once

#include <iostream>
#include "ColumnNode.h"

class ColumnList
{
	public:
		ColumnList();
		void addColumn(Column col); // add column to list
		void removeColumn(std::string name); // remove column by name
		void show(bool showValue);

	private:
		ColumnNode *head;
};

