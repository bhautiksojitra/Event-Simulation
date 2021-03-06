#include "Event.h"
class Process;
class Simulation;

class Timeout : public Event
{
public:
    Timeout(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};