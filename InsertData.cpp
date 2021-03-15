#include "InsertData.h"

using namespace std;

InsertData::InsertData(Table* table1)
{
	table = table1;
}

void InsertData::render()
{
	vector<Column> cols = table->structure;

	vector<Column> data;

	cout << "\n** Insert into \"" << table->name << "\" **\n" << endl;

	for (unsigned int i = 0; i < cols.size(); i++)
	{
		Column currentCol = cols.at(i);
		Column newCol = Column();

		newCol.name = currentCol.name;

		cout << currentCol.name << ": ";
		cin >> newCol.value;

		data.push_back(newCol);
	}

	Row row = Row(data);

	table->data.push_back(row);

	table->saveData();
}
