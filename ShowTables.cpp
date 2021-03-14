#include "ShowTables.h"

using namespace std;

ShowTables::ShowTables()
{
	tables = TableList();
}

ShowTables::ShowTables(TableList tables1)
{
	tables = tables1;
}

void ShowTables::render()
{

	int tableNumber;

	cout << "\n** Tables **" << endl;
	showTableNames();
	cout << "Table Number: " << endl;
	cin >> tableNumber;

	int opt;

	opt = menu();

	switch (opt)
	{
		case 1:
			showStructure();
			break;
	}
}

void ShowTables::showTableNames()
{
	cout << endl;

	for (int i = 0; i < tables.getSize(); i++)
		cout << i + 1 << ") " << tables.getTableByIndex(i).name << endl;
}

int ShowTables::menu()
{
	int opt;

	do
	{
		cout << "\n1. Show Structure" << endl;
		cout << "2. Show Data" << endl;
		cout << "0. Back" << endl;
		cout << "\nOption: ";

		cin >> opt;
	} while (opt < 0 || opt > 2);

	return opt;
}

void ShowTables::showStructure()
{
	for (int i = 0; i < tables.getSize(); i++)
	{
		cout << "\n** " << tables.getTableByIndex(i).name << " **" << endl;
		cout << endl;

		ColumnList cols = tables.getTableByIndex(i).structure;

		for (int j = 0; j < cols.getSize(); j++)
			cout << j + 1 << ") " << cols.getColumnByIndex(j).name << endl;
	}
}