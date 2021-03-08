#pragma once

class Process;
class Simulation;
#include "Event.h"

class Arrival : public Event
{
private:
    bool statusCPU;

public:
    Arrival(int, Process *, Simulation *);
    int compareTo(ListItem *);
    void handleEvent();
    void printEvent();
};