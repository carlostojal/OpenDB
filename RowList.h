#pragma once

#include "RowNode.h"

class RowList
{
	public:
		RowList();
		void addRow(Row row);
		Row* getRowByIndex(int index);
		void removeRowByIndex(int index);
		int getSize();

	private:
		RowNode* head;
};

