/*--------------------------------------------------------------

    File       : ParentQueue.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Impletements the Parent Queue - Super class for other data structures
                
                    - prevents duplication the code
                    - implements the comman methods of its sub classes

-------------------------------------------------------------------*/

#include "ParentQueue.h"
#include "Node.h"

//contructor
ParentQueue::ParentQueue() : front(nullptr), back(nullptr), size(0) {}

// returns the size of the data present in the Queue
int ParentQueue::getSize()
{
    return size;
}
// check if its empty or not
bool ParentQueue::isEmpty()
{
    return size == 0;
}

//Polymorphic method - implemented in the sub classes
//  - in priorityQueue Insertion occurs based on the prioirty of the ListItem
//  - in Queue - Insertion occurs at the end of the list
//doesn't need to be implemented here
void ParentQueue::enqueue(ListItem *item)
{
}

// remove the element from the queue
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

// returns the front element from the queue
ListItem *ParentQueue::getFront()
{
    ListItem *theItem = nullptr;
    if (front != nullptr)
    {
        theItem = front->getItem();
    }
    return theItem;
} // getFront