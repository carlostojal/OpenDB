#include "Table.h"

#include <fstream>
#include <cstdio>

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

void Table::save()
{
	// append to table list
	ofstream f("data/tables.list");
	f << name << endl;
	f.close();

	// create/recreate table structure file
	string path = "data/" + name + ".struct";

	remove(path.c_str()); // remove old file

	ofstream f1(path);
	for (unsigned int i = 0; i < structure.size(); i++)
	{
		cout << structure.at(i).name << endl;
		f1 << structure.at(i).name << ";";
	}
	f1 << endl;
	f1.close();
}