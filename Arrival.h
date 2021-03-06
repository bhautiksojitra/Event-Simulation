#pragma once

class Process;
class Simulation;
#include "Event.h"

class Arrival : public Event
{
public:
    Arrival(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};