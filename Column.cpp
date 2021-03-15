#include "Column.h"

using namespace std;

Column::Column()
{
	name = "";
	value = "";
}

Column::Column(string name1)
{
	name = name1;
	value = "";
}

Column::Column(string name1, string value1)
{
	name = name1;
	value = value1;
}