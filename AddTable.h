#pragma once

#include <iostream>
#include "Table.h"

class AddTable
{
	public:
		AddTable();
		void render();
		void save();
	
	private:
		Table table;
		int renderMenu();
		void addColumn();
		void listColumns();
};

