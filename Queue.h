#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;

class Queue : public ParentQueue
{

public:
	Queue();
	//int getSize();
	//bool isEmpty();
	void enqueue(ListItem *item);
	//ListItem *getFront();
	//ListItem *dequeue();
};
