#include "Table.h"

#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>

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

void Table::load(string name1)
{
	name = name1;

	vector<string> row;
	string path, word, temp;

	path = "data/" + name + ".struct";

	ifstream f(path);

	while (f >> temp)
		structure.push_back(Column(temp));

	f.close();

	path = "data/" + name + ".data";

	ifstream f1(path);

	while (f1 >> temp)
	{
		Row r = Row();

		row.clear();

		stringstream s(temp);

		while (getline(s, word, ';'))
			row.push_back(word);

		for (unsigned int i = 0; i < structure.size(); i++)
			r.cols.push_back(Column(structure.at(i).name, row.at(i)));

		data.push_back(r);
	}

	f1.close();
}

void Table::saveStructure()
{

	// append to table list
	ofstream f;
	f.open("data/tables.list", ios_base::app);
	f << name << endl;
	f.close();

	// create/recreate table structure file
	string path = "data/" + name + ".struct";

	ofstream f1(path);
	for (unsigned int i = 0; i < structure.size(); i++)
		f1 << structure.at(i).name << endl;
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