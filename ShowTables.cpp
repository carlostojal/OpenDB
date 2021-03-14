#include "ShowTables.h"

using namespace std;

ShowTables::ShowTables()
{
	tables = new TableList();
}

ShowTables::ShowTables(TableList* tables1)
{
	tables = tables1;
}

void ShowTables::render()
{

	int tableNumber;

	cout << "\n** Tables **" << endl;
	showTableNames();
	cout << "\nTable Number: ";
	cin >> tableNumber;

	Table* table = tables->getTableByIndex(tableNumber - 1);

	int opt;

	opt = menu();

	switch (opt)
	{
		case 1:
			showStructure(*table);
			break;
		case 2:
			showData(*table);
	}
}

void ShowTables::showTableNames()
{
	cout << endl;

	for (int i = 0; i < tables->getSize(); i++)
		cout << i + 1 << ") " << tables->getTableByIndex(i)->name << endl;
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

void ShowTables::showStructure(Table table)
{
	cout << "\n** " << table.name << " **" << endl;
	cout << endl;

	ColumnList cols = table.structure;

	for (int i = 0; i < cols.getSize(); i++)
		cout << i + 1 << ") " << cols.getColumnByIndex(i).name << endl;
}

void ShowTables::showData(Table table)
{
	cout << "\n** " << table.name << " **" << endl;
	cout << endl;

	ColumnList cols = table.structure;
	RowList rows = table.data;

	for (int i = 0; i < cols.getSize(); i++)
		cout << cols.getColumnByIndex(i).name << "\t|\t";

	cout << endl;

	for (int i = 0; i < rows.getSize(); i++)
	{
		for (int j = 0; j < rows.getRowByIndex(i)->cols.getSize(); j++)
			cout << rows.getRowByIndex(i)->cols.getColumnByIndex(j).value << "\t|\t";
		cout << endl;
	}
}