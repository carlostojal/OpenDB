#include "Table.h"

Table::Table()
{
	name = "";
}

Table::Table(string name1)
{
	name = name1;
}

Table::Table(string name1, vector<Column> structure1)
{
	name = name1;
	structure = structure1;
}