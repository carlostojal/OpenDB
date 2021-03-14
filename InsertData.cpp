#include "InsertData.h"

using namespace std;

InsertData::InsertData()
{
	tables = new TableList();
}

InsertData::InsertData(TableList* tables1)
{
	tables = tables1;
}

void InsertData::render()
{

	int tableNumber;

	cout << "\n** Tables **" << endl;
	showTableNames();
	cout << "\nTable Number: ";
	cin >> tableNumber;

	Table* table = tables->getTableByIndex(tableNumber - 1);

	insert(table);
}

void InsertData::showTableNames()
{
	cout << endl;

	for (int i = 0; i < tables->getSize(); i++)
		cout << i + 1 << ") " << tables->getTableByIndex(i)->name << endl;
}

void InsertData::insert(Table* table)
{
	ColumnList cols = table->structure;

	ColumnList data = ColumnList();

	for (int i = 0; i < cols.getSize(); i++)
	{
		Column currentCol = cols.getColumnByIndex(i);
		Column newCol = Column();

		newCol.name = currentCol.name;

		cout << currentCol.name << ": ";
		cin >> newCol.value;

		data.addColumn(newCol);
	}

	Row row = Row(data);

	table->data.addRow(row);
}
