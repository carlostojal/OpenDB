#pragma once

#include "Row.h"

class RowNode
{
	public:
		RowNode();
		RowNode(Row row);
		Row value;
		RowNode* next;
};

