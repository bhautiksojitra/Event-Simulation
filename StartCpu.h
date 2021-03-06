#include "Event.h"
class StartCpu : public Event
{
private:
    bool isBurstEnough;

public:
    StartCpu(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};