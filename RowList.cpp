#include "RowList.h"

RowList::RowList()
{
	head = NULL;
}

void RowList::addRow(Row row)
{
	RowNode* node = new RowNode(row);

	if (head == NULL)
	{
		head = node;
	}
	else
	{
		RowNode* temp = head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}
}

Row* RowList::getRowByIndex(int index)
{
	RowNode* temp = head;

	int i = 0;

	while (temp != NULL)
	{
		if (i == index)
			return &temp->value;
		i++;

		temp = temp->next;
	}

	return new Row();
}

void RowList::removeRowByIndex(int index)
{
	RowNode* temp = head;

	int i = 0;

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

int RowList::getSize()
{
	int size = 0;

	RowNode* temp = head;

	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}

	return size;
}