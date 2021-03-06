class Queue;
class Burst;
#include "ListItem.h"

class Process : public ListItem
{
private:
    int arrivalTime;
    int id;
    Queue *cpuQueue;
    Queue *ioQueue;

public:
    Process(int, int);
    int compareTo(ListItem *other);
    int getId();
    int getCpuBurst();
    int getIOBurst();

    void addCPUBurst(int);
    void addIOBurst(int);

    void removeIOBurst();
    void removeCPUBurst();
};