#include "Process.h"
#include "Queue.h"
#include "Burst.h"

using namespace std;

Process::Process(int theArrivalTime, int theId)
{
    arrivalTime = theArrivalTime;
    id = theId;
    cpuQueue = new Queue();
    ioQueue = new Queue();
}

//change it
int Process::compareTo(ListItem *other)
{
    return 0;
}

int Process::getId()
{
    return id;
}

void Process::addCPUBurst(int value)
{
    Burst *newBurst = new Burst(value);
    cpuQueue->enqueue(newBurst);
}

void Process::removeCPUBurst()
{
    cpuQueue->dequeue();
}

void Process::addIOBurst(int value)
{
    Burst *newBurst = new Burst(value);
    ioQueue->enqueue(newBurst);
}

void Process::removeIOBurst()
{
    ioQueue->dequeue();
}

int Process::getCpuBurst()
{
    Burst *topBurst = dynamic_cast<Burst *>(cpuQueue->getFront());

    if (topBurst != nullptr)
    {
        return topBurst->getIntValue();
    }

    return -1;
}

int Process::getIOBurst()
{
    Burst *topBurst = dynamic_cast<Burst *>(ioQueue->getFront());

    if (topBurst != nullptr)
    {
        return topBurst->getIntValue();
    }

    return 0;
}
