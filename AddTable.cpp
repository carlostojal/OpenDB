#include "AddTable.h"

#include <fstream>

AddTable::AddTable()
{
	table = Table();
}

Table AddTable::render()
{
	int menuOpt;
	
	std::cout << "\n** Add Table **" << std::endl;
	std::cout << "\nName: ";
	std::cin >> table.name;
	
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
	save();

	return table;
}

int AddTable::renderMenu()
{
	int opt;
	do
	{
		std::cout << "\n1. Add Column" << std::endl;
		std::cout << "2. Remove Column" << std::endl;
		std::cout << "3. List Columns" << std::endl;
		std::cout << "0. Back" << std::endl;
		std::cout << "\nOption: ";
		std::cin >> opt;

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
	table.structure.addColumn(col);
}

void AddTable::removeColumn()
{
	int index;

	do 
	{
		std::cout << "\n** Remove Column **" << std::endl;
		std::cout << "\nNumber: ";
		std::cin >> index;
	} while (index < 1 || index > table.structure.getSize());

	table.structure.removeColumnByIndex(index - 1);
}

void AddTable::listColumns()
{
	std::cout << "\n** List Columns **\n" << std::endl;

	for (int i = 0; i < table.structure.getSize(); i++)
		std::cout << i + 1 << ") " << table.structure.getColumnByIndex(i).name << std::endl;
}


void AddTable::save()
{
	std::ofstream f("data/" + table.name + ".struct");
	
	for (int i = 0; i < table.structure.getSize(); i++)
		f << table.structure.getColumnByIndex(i).name << std::endl;

	f.close();
}