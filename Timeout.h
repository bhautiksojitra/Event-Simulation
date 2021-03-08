#include "Event.h"
class Process;
class Simulation;

class Timeout : public Event
{
private:
    int remainingBurst;

public:
    Timeout(int, Process *, Simulation *);
    int compareTo(ListItem *);
    void handleEvent();
    void printEvent();
};