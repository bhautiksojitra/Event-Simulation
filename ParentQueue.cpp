#include "ParentQueue.h"
#include "Node.h"

/**** ParentQueue implementation */
ParentQueue::ParentQueue() : front(nullptr), back(nullptr), size(0) {}

int ParentQueue::getSize()
{
    return size;
}
bool ParentQueue::isEmpty()
{
    return size == 0;
}

void ParentQueue::enqueue(ListItem *item)
{
}

ListItem *ParentQueue::dequeue()
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

ListItem *ParentQueue::getFront()
{
    ListItem *theItem = nullptr;
    if (front != nullptr)
    {
        theItem = front->getItem();
    }
    return theItem;
} // getFront