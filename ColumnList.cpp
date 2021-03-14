#include "ColumnList.h"

ColumnList::ColumnList()
{
	head = NULL;
}

void ColumnList::addColumn(Column col)
{
	// the new node to be inserted based on a column
	ColumnNode* node = new ColumnNode(col);

	// temporary node to iterate list
	

	// is the first list node
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		ColumnNode* temp = head;

		// iterate list
		while (temp->next != NULL)
			temp = temp->next;

		// add to tail
		temp->next = node;
	}
}

void ColumnList::removeColumn(std::string name)
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

void ColumnList::show(bool showValue) 
{
	ColumnNode* temp = head;
	while (temp != NULL)
	{
		std::cout << "Name: " << temp->value.name << std::endl;
		if (showValue)
			std::cout << "Value: " << temp->value.value << std::endl;

		temp = temp->next;
	}
}