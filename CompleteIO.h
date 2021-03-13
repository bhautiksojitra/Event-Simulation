/*--------------------------------------------------------------

    File       : CompleteIO.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Header file for the Complete I/O Event 

-------------------------------------------------------------------*/
#pragma once // prevents multiple includes of the Header file

#include "Event.h" // Sub class of the Event

//Forward Reference of the required classes
class Process;
class Simulation;

class CompleteIO : public Event
{

public:
    CompleteIO(int, Process *, Simulation *); // Constructor
    void handleEvent() override;
    void printEvent() override;
};