/*--------------------------------------------------------------

    File       : PriorityQueue.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :   Implements the queue for which works based on the priority of the elements 

-------------------------------------------------------------------*/
#include <iostream>

#include "ListItem.h"
#include "Node.h"
#include "PriorityQueue.h"
#include "Event.h"

//Constructor - Indirectly calls the constructor of Parent Queue
PriorityQueue::PriorityQueue() : ParentQueue() {}

//Overridden polymorphic method
void PriorityQueue::enqueue(ListItem *item)
{
    //creates the node
    Node *newNode = new Node(item, nullptr);

    //Iterate through the list and checks the right position to insert the node
    Node *curr;

    // if the list is empty or the item has higher priority than the first element than
    // add thta item to the first place
    if (front == nullptr || (item->compareTo(front->getItem()) == 1))
    {
        newNode->setNext(front);
        front = newNode;
    }
    else
    {
        curr = front;

        //Interate through the list untill it finds the right place
        while (curr->getNext() != nullptr && (item->compareTo(curr->getNext()->getItem()) == 0))
        {
            curr = curr->getNext();
        }

        //add the node in the list
        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
    }

    size++; // Increment the size by 1
} // Enqueue
