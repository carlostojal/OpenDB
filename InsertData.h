#pragma once

#include <vector>
#include "Table.h"

class InsertData
{
	public:
		InsertData(Table* table);
		void render();

	private:
		Table* table;
		
};

