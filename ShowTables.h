#pragma once

#include <vector>
#include "TableList.h"

class ShowTables
{
	public:
		ShowTables(vector<Table>* tables);
		void render();

	private:
		vector<Table>* tables;
		void showTableNames();
		int menu();
		void showStructure(Table table);
		void showData(Table table);
};

