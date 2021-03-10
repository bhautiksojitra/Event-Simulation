/*--------------------------------------------------------------

    File       : Arrival.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Header file for the Arrival Event 

-------------------------------------------------------------------*/
#pragma once // To handle multiple include of the same header file

// Forward Reference to the required classes
class Process;
class Simulation;

// including header file of the parent class
#include "Event.h"

class Arrival : public Event // Event SuperClass
{

public:
    Arrival(int, Process *, Simulation *); //constructor

    //polymorphic methods
    void handleEvent() override;
    void printEvent() override;
};