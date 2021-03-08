#pragma once
#include "Event.h"
class StartIO : public Event
{
public:
    StartIO(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};