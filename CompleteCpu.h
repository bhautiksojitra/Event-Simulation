/*--------------------------------------------------------------

    File       : CompleteCpu.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the CompleteCpu Event 

-------------------------------------------------------------------*/
//Sub class of Event
#pragma once
#include "Event.h"

class Process;
class Simulation;

class CompleteCpu : public Event
{

public:
    CompleteCpu(int, Process *, Simulation *);
    void handleEvent() override;
    void printEvent() override;
};