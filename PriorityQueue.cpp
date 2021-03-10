#include <iostream>

#include "ListItem.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Event.h"

PriorityQueue::PriorityQueue() : ParentQueue() {}

void PriorityQueue::enqueue(ListItem *item)
{
    Node *newNode = new Node(item, nullptr);

    Node *curr;

    if (front == nullptr || (item->compareTo(front->getItem()) == 1))
    {
        newNode->setNext(front);
        front = newNode;
    }
    else
    {
        curr = front;

        while (curr->getNext() != nullptr && (item->compareTo(curr->getNext()->getItem()) == 0))
        {
            curr = curr->getNext();
        }

        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
    }

    size++;
}
