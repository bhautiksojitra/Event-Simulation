#include <iostream>
#include "ListItem.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Event.h"

PriorityQueue::PriorityQueue()
{
    top = nullptr;
    size = 0;
}

void PriorityQueue::enqueue(Event *item)
{
    Node *temp=new Node(item, nullptr);

    Node * curr;//pointer to current Node


    if(top == nullptr || item->compareTo(dynamic_cast<ListItem *>(top->getItem())) == 1)
    {
        temp->setNext(top);
        top=temp;
    }
    else
    {

        curr=top;
        while(curr->getNext()!= nullptr && item->compareTo(dynamic_cast<ListItem *>(curr->getNext()->getItem()))==0)
        {

            curr=curr->getNext();
        }

       temp->setNext(curr->getNext());
       curr->setNext(temp);
    }
    size++;
}//end enqueue

ListItem * PriorityQueue::extractMax()
{
    ListItem* highestPriority = nullptr;
    Node * theNode=top;
    if(theNode!= nullptr)
    {
        highestPriority= dynamic_cast<ListItem *>(theNode->getItem());
        //special case removing the last node
        if(top->getNext()== nullptr)
        {
            top= nullptr;
        }else
        {
            top=top->getNext();
        }

        delete(theNode);
        size--;
    }
    return highestPriority;
}//dequeue
bool PriorityQueue::isEmpty()
{
    bool isTopNull = false;
    if (top == nullptr)
    {
        isTopNull = true;
    }
    return isTopNull;
}

int PriorityQueue::getSize()
{
    return size;
}
