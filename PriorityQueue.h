#pragma once
// Forward Reference of the class.
class Node;
class ListItem;
#include "Queue.h"
class Event;
#pragma once

//Interface
class PriorityQueue
{
private:
    Node *top;
    int size;

public:
    PriorityQueue(); // Constructor

    void enqueue(Event *); // add the data in the Queue;

    ListItem *extractMax(); // retrieve the data with the max priority and remove it.
    bool isEmpty();      // checks whether the list is empty
    int getSize();
};