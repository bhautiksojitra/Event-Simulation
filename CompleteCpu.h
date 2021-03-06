#include "Event.h"
class Process;
class Simulation;

class CompleteCpu : public Event
{
public:
    CompleteCpu(int, Process *, Simulation *);
    void handleEvent();
    void printEvent();
};