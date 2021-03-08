#pragma once
#include "Event.h"
class Process;
class Simulation;

class Exit : public Event
{
public:
    Exit(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};