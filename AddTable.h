#pragma once

#include <iostream>
#include "Table.h"

class AddTable
{
	public:
		AddTable();
		Table render();
		void save();
	
	private:
		Table table;
		int renderMenu();
		void addColumn();
		void removeColumn();
		void listColumns();
};

