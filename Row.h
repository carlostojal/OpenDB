#pragma once

#include "Column.h"

#include <vector>

using namespace std;

class Row
{
	public:
		Row();
		Row(vector<Column> cols);
		vector<Column> cols;
};

