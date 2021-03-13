/*--------------------------------------------------------------

    File       : ParentQueue.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface of the ParentQueue 

-------------------------------------------------------------------*/
#pragma once // prevents multiple includes of the header file

//Forward reference of the classes required
class Node;
class ListItem;

//Abstract class
class ParentQueue
{
    //Make it protected beacuse we can use those fields in the sub classes
protected:
    Node *front;
    Node *back;
    int size;

public:
    ParentQueue();  // constructor
    int getSize();  // return the size of the data
    bool isEmpty(); // retuns true if list has no element

    //Polymorphic methods - can implements different functionality
    virtual void enqueue(ListItem *item) = 0;

    ListItem *getFront(); // retrieve first element from the list
    ListItem *dequeue();  // remove th element from the list

}; // class ParentQueue