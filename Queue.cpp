#include "Queue.h"
#include "ListItem.h"
#include "Node.h"

/**** Queue implementation */
Queue::Queue() : ParentQueue() {}

void Queue::enqueue(ListItem *item)
{
	// special case: adding to empty queue
	if (front == nullptr)
	{
		front = new Node(item, nullptr);
		back = front;
	}
	else
	{
		back->setNext(new Node(item, nullptr));
		back = back->getNext();
	}
	size++;
} // enqueue
