#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;

class Queue : public ParentQueue
{
public:
	Queue();
	void enqueue(ListItem *item);
};
