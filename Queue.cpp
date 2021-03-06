#include "Queue.h"
#include "ListItem.h"
#include "Node.h"

/**** Queue implementation */
Queue::Queue() : front(nullptr), back(nullptr), size(0) {}
int Queue::getSize()
{
	return size;
}
bool Queue::isEmpty()
{
	return size == 0;
}

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

ListItem *Queue::dequeue()
{
	ListItem *theItem = nullptr;
	Node *theNode = front;
	if (front != nullptr)
	{
		theItem = front->getItem();
		// special case: removing last item
		if (front == back)
		{
			front = back = nullptr;
		}
		else
		{
			front = front->getNext();
		}
		size--;
		delete (theNode);
	}
	return theItem;
} // dequeue

ListItem *Queue::getFront()
{
	ListItem *theItem = nullptr;
	if (front != nullptr)
	{
		theItem = front->getItem();
	}
	return theItem;
} // getFront

ListItem *Queue::getMax()
{
	ListItem *maxItem = this->getFront();

	Node *curr = front;

	while (curr != nullptr)
	{
		if (curr->getItem()->compareTo(maxItem) > 0)
		{
			maxItem = curr->getItem();
		}

		curr = curr->getNext();
	}

	return maxItem;
}

ListItem *Queue::extractMax()
{
	ListItem *maxItem = this->getMax();

	if (!isEmpty())
	{
		Node *previous = nullptr;
		Node *current = front;

		while (current != nullptr && (current->getItem()) != maxItem)
		{
			previous = current;
			current = current->getNext();
		}

		if (current != nullptr && previous != nullptr)
		{
			previous->setNext(current->getNext());
			current->setNext(nullptr);
		}
		else if (previous == nullptr)
		{
			front = front->getNext();
		}

		return maxItem;
	}
	else
	{
		return nullptr;
	}
}

void Queue::print()
{
	Node *temp = front;

	while (temp != nullptr)
	{

		temp = temp->getNext();
	}
}