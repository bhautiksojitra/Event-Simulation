
/*--------------------------------------------------------------

    File       : PriorityQueue.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the Priority Queue 

-------------------------------------------------------------------*/
#pragma once
// Forward Reference of the class.
class ListItem;

#include "ParentQueue.h"

//Interface
class PriorityQueue : public ParentQueue
{

public:
    PriorityQueue();          // Constructor
    void enqueue(ListItem *); // add the data in the Queue;
};