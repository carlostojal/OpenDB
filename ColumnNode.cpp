#include "ColumnNode.h"

ColumnNode::ColumnNode()
{
	value = Column();
	next = NULL;
}

ColumnNode::ColumnNode(Column col)
{
	value = col;
	next = NULL;
}