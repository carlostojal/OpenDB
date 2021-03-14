#include "ColumnList.h"

ColumnList::ColumnList()
{
	head = NULL;
}

void ColumnList::addColumn(Column col)
{
	// the new node to be inserted based on a column
	ColumnNode* node = new ColumnNode(col);

	// is the first list node
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		// temporary node to iterate list
		ColumnNode* temp = head;

		// iterate list
		while (temp->next != NULL)
			temp = temp->next;

		// add to tail
		temp->next = node;
	}
}

Column ColumnList::getColumnByIndex(int index)
{
	ColumnNode* temp = head;

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

	return Column();
}

void ColumnList::removeColumnByIndex(int index)
{
	ColumnNode* temp = head;

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

void ColumnList::removeColumnByName(std::string name)
{
	ColumnNode* temp = head;

	// iterate list
	while (temp->next != NULL)
	{
		// if the next column name matches, the next will be its next (removes next)
		if (temp->next->value.name.compare(name) == 0)
			temp->next = temp->next->next;
		temp = temp->next;
	}
}

int ColumnList::getSize()
{
	int size = 0;

	ColumnNode* temp = head;

	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}

	return size;
}