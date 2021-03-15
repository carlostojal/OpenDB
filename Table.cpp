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

void Table::saveStructure()
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
		f1 << structure.at(i).name << ";";
	f1 << endl;
	f1.close();
}

void Table::saveData()
{
	// create/recreate table structure file
	string path = "data/" + name + ".data";

	remove(path.c_str()); // remove old file

	ofstream f(path);
	for (unsigned int i = 0; i < data.size(); i++)
	{
		for (unsigned int j = 0; j < data.at(i).cols.size(); j++)
			f << data.at(i).cols.at(j).value << ";";
		f << endl;
	}
	f.close();
}