#pragma once
#include "Event.h"
class Process;
class Simulation;

class CompleteIO : public Event
{
public:
    CompleteIO(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};