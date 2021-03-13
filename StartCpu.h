/*--------------------------------------------------------------

    File       : StartCpu.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the StratCpu event


-------------------------------------------------------------------*/
#pragma once // prevents multiple includes of header file

#include "Event.h"

//sunb class of event class
class StartCpu : public Event
{
public:
    StartCpu(int, Process *, Simulation *);
    void handleEvent() override;
    void printEvent() override;
};