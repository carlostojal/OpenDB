#pragma once

#include <iostream>
#include "Column.h"

class ColumnNode
{
	public:
		ColumnNode();
		ColumnNode(Column col);
		Column value;
		ColumnNode* next;
};

