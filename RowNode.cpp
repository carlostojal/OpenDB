#include "RowNode.h"

RowNode::RowNode()
{
	value = Row();
	next = NULL;
}

RowNode::RowNode(Row row)
{
	value = row;
	next = NULL;
}