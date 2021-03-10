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
    void handleEvent();
    void printEvent();
};