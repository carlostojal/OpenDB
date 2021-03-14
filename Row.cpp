#include "Row.h"

Row::Row()
{
	cols = ColumnList();
}

Row::Row(ColumnList cols1)
{
	cols = cols1;
}