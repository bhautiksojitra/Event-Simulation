#pragma once

class Node;
class ListItem;

class ParentQueue
{
protected:
    Node *front;
    Node *back;
    int size;

public:
    ParentQueue();
    int getSize();
    bool isEmpty();
    virtual void enqueue(ListItem *item) = 0;
    ListItem *getFront();
    ListItem *dequeue();
}; // class ParentQueue