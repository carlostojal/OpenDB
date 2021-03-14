#pragma once

#include <iostream>
#include "Table.h"

class TableNode
{
	public:
		TableNode();
		TableNode(Table table);
		Table value;
		TableNode* next;
};

