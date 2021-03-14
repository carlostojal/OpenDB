#include "Table.h"

Table::Table()
{
	name = "";
	structure = ColumnList();
}

Table::Table(std::string name1)
{
	name = name1;
}

Table::Table(std::string name1, ColumnList structure1)
{
	name = name1;
	structure = structure1;
}