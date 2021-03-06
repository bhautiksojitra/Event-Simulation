#include "Event.h"
class StartCpu : public Event
{
public:
    StartCpu(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};