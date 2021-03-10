#pragma once
// Forward Reference of the class.
class ListItem;

#include "ParentQueue.h"

//Interface
class PriorityQueue : public ParentQueue
{

public:
    PriorityQueue(); // Constructor
    void enqueue(ListItem *); // add the data in the Queue;

};