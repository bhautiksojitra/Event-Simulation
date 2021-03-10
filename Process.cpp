
#include "Process.h"
#include "Queue.h"
#include "Burst.h"
#include "ParentQueue.h"

#include <iostream>

using namespace std;

Process::Process(int theArrivalTime, int theId)
{
    arrivalTime = theArrivalTime;
    totalBurstsTime = 0;
    exitTime = 0;
    waitTime = 0;
    id = theId;
    cpuQueue = new Queue();
    ioQueue = new Queue();
}

int Process::compareTo(ListItem *other)
{
    return 0;
}

int Process::getId()
{
    return id;
}

int Process::getArrivalTime()
{
    return arrivalTime;
}

int Process::getTotalBurstsTime()
{
    return totalBurstsTime;
}

int Process::getExitTime()
{
    return exitTime;
}

int Process::getWaitTime()
{
    return waitTime;
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

    return 0;
}

void Process::setCpuBurst(int newValue)
{
    Burst *topBurst = dynamic_cast<Burst *>(cpuQueue->getFront());

    if (topBurst != nullptr)
    {
        return topBurst->setIntValue(newValue);
    }
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

void Process::setExitTime(int newTime)
{
    exitTime = newTime;
}

void Process::setWaitTime(int newTime)
{
    waitTime = newTime;
}

void Process::incrementBurstTime(int newValue)
{
    totalBurstsTime = totalBurstsTime + newValue;
}

void Process::print()
{
    
    cout << "    " << getId() << "    "
         << "    " << getArrivalTime() << "    "
         << "        " << getExitTime() << "    "
         << "        " << getWaitTime() << endl;
} 
