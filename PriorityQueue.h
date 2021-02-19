#pragma once
// Forward Reference of the class.
class Node;
class ListItem;

//Interface
class PriorityQueue
{
    private:
        PriorityNode* head; // Pointer to the top Node in the P-Queue
        int size;
        
    public:
        PriorityQueue(); // Constructor
        void push(); // add the data in the Queue;
        ListItem* getMax();  // to get the data with the max priority 
        ListItem* extractMax(); // retrieve the data with the max priority and remove it.
        int size(); // return the size of the list. 
};