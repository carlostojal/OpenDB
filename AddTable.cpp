#include "AddTable.h"

AddTable::AddTable()
{
	table = Table();
}

void AddTable::render()
{
	int menuOpt;
	
	std::cout << "** Add Table **" << std::endl;
	std::cout << "Name: ";
	std::cin >> table.name;
	
	do
	{
		menuOpt = renderMenu();

		switch (menuOpt)
		{
			case 1:
				addColumn();
				break;
			case 2:
				table.structure.show(false);
				break;
		}

	} while (menuOpt != 0);
}

int AddTable::renderMenu()
{
	int opt;
	do
	{
		std::cout << "1. Add Column" << std::endl;
		std::cout << "2. List Columns" << std::endl;
		std::cout << "0. Finish" << std::endl;
		std::cout << "Option: ";
		std::cin >> opt;

	} while (opt < 0 || opt > 2);

	return opt;
}

void AddTable::addColumn()
{
	Column col = Column();

	// read table data
	std::cout << "** Add Column **" << std::endl;
	std::cout << "Name: ";
	std::cin >> col.name;

	// adds the column created to the table structure
	table.structure.addColumn(col);
}



void AddTable::save()
{

}