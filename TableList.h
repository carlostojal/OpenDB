#pragma once

#include <iostream>
#include "TableNode.h"

class TableList
{
	public:
		TableList();
		void addTable(Table table);
		Table getTableByIndex(int index);
		void removeTableByIndex(int index);
		int getSize();

	private:
		TableNode* head;

};

