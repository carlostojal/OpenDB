#pragma once

#include "ColumnList.h"

class Row
{
	public:
		Row();
		Row(ColumnList cols);
		ColumnList cols;
};

