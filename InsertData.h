#pragma once

#include "TableList.h"

class InsertData
{
	public:
		InsertData();
		InsertData(TableList* tables);
		void render();

	private:
		TableList* tables;
		void showTableNames();
		void insert(Table* table);
		
};

