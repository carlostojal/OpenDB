#include "AddTable.h"

#include <fstream>

using namespace std;

AddTable::AddTable()
{
	// new table to be added
	table = Table();
}

Table AddTable::render()
{
	int menuOpt;
	
	cout << "\n** Add Table **" << endl;
	cout << "\nName: ";
	cin >> table.name;
	
	// show menu until the "finish" option is chosen
	do
	{
		// option comes from the menu rendering function
		menuOpt = renderMenu();

		switch (menuOpt)
		{
			case 1:
				addColumn();
				break;
			case 2:
				removeColumn();
				break;
			case 3:
				listColumns();
				break;
		}

	} while (menuOpt != 0);

	// save in the end of execution
	table.save();

	return table;
}

int AddTable::renderMenu()
{
	int opt;
	do
	{
		cout << "\n1. Add Column" << endl;
		cout << "2. Remove Column" << endl;
		cout << "3. List Columns" << endl;
		cout << "0. Back" << endl;
		cout << "\nOption: ";
		cin >> opt;

	} while (opt < 0 || opt > 3);

	return opt;
}

void AddTable::addColumn()
{
	Column col = Column();

	// read table data
	std::cout << "\n** Add Column **" << std::endl;
	std::cout << "\nName: ";
	std::cin >> col.name;

	// adds the column created to the table structure
	table.structure.push_back(col);
}

void AddTable::removeColumn()
{
	unsigned int index;

	do 
	{
		std::cout << "\n** Remove Column **" << std::endl;
		std::cout << "\nNumber: ";
		std::cin >> index;
	} while (index < 1 || index > table.structure.size());

	table.structure.erase(table.structure.begin() + index - 1);
}

void AddTable::listColumns()
{
	std::cout << "\n** List Columns **\n" << std::endl;

	for (unsigned int i = 0; i < table.structure.size(); i++)
		std::cout << i + 1 << ") " << table.structure.at(i).name << std::endl;
}