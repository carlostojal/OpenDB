#include <vector>

#include "ShowTables.h"
#include "InsertData.h"

using namespace std;

ShowTables::ShowTables(vector<Table>* tables1)
{
	tables = tables1;
}

void ShowTables::render()
{

	int tableNumber;

	cout << "\n** Tables **" << endl;

	if (tables->size() == 0)
	{
		cout << "\nNo tables." << endl;
	}
	else
	{
		showTableNames();
		cout << "\nTable Number: ";
		cin >> tableNumber;

		Table* table = &tables->at(tableNumber - 1);

		int opt;

		do
		{
			opt = menu();

			switch (opt)
			{
			case 1:
				showStructure(*table);
				break;
			case 2:
				showData(*table);
				break;
			case 3:
				InsertData(table).render();
				break;
			}

		} while (opt != 0);
	}
}

void ShowTables::showTableNames()
{
	for (unsigned int i = 0; i < tables->size(); i++)
		cout << i + 1 << ") " << tables->at(i).name << endl;
}

int ShowTables::menu()
{
	int opt;

	do
	{
		cout << "\n1. Show Structure" << endl;
		cout << "2. Show Data" << endl;
		cout << "3. Insert Data" << endl;
		cout << "0. Back" << endl;
		cout << "\nOption: ";

		cin >> opt;
	} while (opt < 0 || opt > 3);

	return opt;
}

void ShowTables::showStructure(Table table)
{
	cout << "\n** " << table.name << " **" << endl;
	cout << endl;

	vector<Column> cols = table.structure;

	for (unsigned int i = 0; i < cols.size(); i++)
		cout << i + 1 << ") " << cols.at(i).name << endl;
}

void ShowTables::showData(Table table)
{
	cout << "\n** " << table.name << " **" << endl;
	cout << endl;

	vector<Column> cols = table.structure;
	vector<Row> rows = table.data;

	for (unsigned int i = 0; i < cols.size(); i++)
		cout << cols.at(i).name << "\t|\t";

	cout << endl;

	for (unsigned int i = 0; i < rows.size(); i++)
	{
		for (unsigned int j = 0; j < rows.at(i).cols.size(); j++)
			cout << rows.at(i).cols.at(j).value << "\t|\t";
		cout << endl;
	}
}