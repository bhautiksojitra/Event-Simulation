/*--------------------------------------------------------------

    File       : StartIO.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the StratIO event


-------------------------------------------------------------------*/
#pragma once // prevents multiple includes of the header file.

#include "Event.h"

//sub class of the event
class StartIO : public Event
{
public:
    StartIO(int, Process *, Simulation *);
    void handleEvent() override;
    void printEvent() override;
};