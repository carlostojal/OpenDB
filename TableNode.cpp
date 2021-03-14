#include "TableNode.h"

TableNode::TableNode()
{
	value = Table();
	next = NULL;
}

TableNode::TableNode(Table table)
{
	value = table;
	next = NULL;
}