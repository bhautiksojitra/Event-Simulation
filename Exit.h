/*--------------------------------------------------------------

    File       : Exit.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface of the Exit class

-------------------------------------------------------------------*/
#pragma once
#include "Event.h"

class Process;
class Simulation;

class Exit : public Event
{
public:
    Exit(int, Process *, Simulation *); // constructor
    void handleEvent() override;
    void printEvent() override;
};