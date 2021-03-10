/*--------------------------------------------------------------

    File       : Burst.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose : header file of the Burst.cpp

-------------------------------------------------------------------*/
#pragma once // manages multiple includes of this file

#include "ListItem.h" // superclass of the burst class

class Burst : public ListItem
{

private:
    int valueOfburst; // field to store time

public:
    //constuctor
    Burst(int);
    //polymorphic method
    int compareTo(ListItem *) override;

    int getIntValue();
    void setIntValue(int);
};