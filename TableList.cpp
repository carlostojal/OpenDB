#include "TableList.h"

TableList::TableList()
{
	head = NULL;
}

void TableList::addTable(Table table)
{
	// the new node to be inserted based on a table
	TableNode* node = new TableNode(table);

	if (head == NULL)
	{
		head = node;
	}
	else
	{
		// temporary node to iterate list
		TableNode* temp = head;

		// iterate list
		while (temp->next != NULL)
			temp = temp->next;

		// add to tail
		temp->next = node;
	}
}

Table TableList::getTableByIndex(int index)
{
	TableNode* temp = head;

	int i = 0;

	// iterate list
	while (temp != NULL)
	{
		// if the index is the one we searching
		if (i == index)
			return temp->value;
		i++;

		temp = temp->next;
	}

	return Table();
}

void TableList::removeTableByIndex(int index)
{
	TableNode* temp = head;

	int i = 0;

	// iterate list
	while (temp->next != NULL)
	{
		if (i + 1 == index)
		{
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
		i++;
	}
}

int TableList::getSize()
{
	int size = 0;

	TableNode* temp = head;

	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}

	return size;
}