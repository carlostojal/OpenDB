#pragma once

#include <iostream>
#include "ColumnNode.h"

class ColumnList
{
	public:
		ColumnList();
		void addColumn(Column col); // add column to list
		Column getColumnByIndex(int index);
		void removeColumnByIndex(int index); // remove column by index
		void removeColumnByName(std::string name); // remove column by name
		int getSize();

	private:
		ColumnNode* head;
};

