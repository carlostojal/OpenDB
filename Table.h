#pragma once

#include <iostream>
#include <vector>
#include "Column.h"
#include "Row.h"

using namespace std;

class Table
{
	public:
		Table();
		Table(string name);
		Table(string name, vector<Column> structure);
		void load(string name);
		void saveStructure();
		void saveData();
		string name;
		vector<Column> structure;
		vector<Row> data;
};

