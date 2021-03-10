/*--------------------------------------------------------------

    File       : Burst.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  - Burst of CPU and I/O which stores the int value.
                  - Int value refers to the amount of time is needed by the process
                    to complete its job in CPU and I/O. 

-------------------------------------------------------------------*/

#include "Burst.h"

//constructor
Burst::Burst(int theValue)
{
    valueOfburst = theValue;
}

//Not needed -  wrote because it is virtual in ListItem class
int Burst::compareTo(ListItem *other)
{
    return 0;
}

//get the value
int Burst::getIntValue()
{
    return valueOfburst;
}

//set the burst value
void Burst::setIntValue(int newValue)
{
    valueOfburst = newValue;
}