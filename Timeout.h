/*--------------------------------------------------------------

    File       : Timeout.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the Timeout event


-------------------------------------------------------------------*/
#pragma once

#include "Event.h"

class Process;
class Simulation;

class Timeout : public Event
{
private:
    int remainingBurst;

public:
    Timeout(int, Process *, Simulation *);
    void handleEvent() override;
    void printEvent() override;
};