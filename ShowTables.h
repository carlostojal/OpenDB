#pragma once

#include "TableList.h"

class ShowTables
{
	public:
		ShowTables();
		ShowTables(TableList tables);
		void render();

	private:
		TableList tables;
		void showTableNames();
		int menu();
		void showStructure();
};

