
/*--------------------------------------------------------------

    File       : Process.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  holds all the info related to the process that is being executed during the simulation 

-------------------------------------------------------------------*/

#include "Process.h"
#include "Queue.h"
#include "Burst.h"

#include <iostream>

using namespace std;

//constructor - initialise all the variables.
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

//comparing two processes - overridden method
int Process::compareTo(ListItem *other)
{

    //dynamic casting safely
    Process *otherProcess = dynamic_cast<Process *>(other);

    if (otherProcess != nullptr)
    {
        //with lower Id - higher priority
        if (this->getId() < otherProcess->getId())
        {
            return 1;
        }
        else if (this->getId() == otherProcess->getId())
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        cout << "the Object you are comparing with is not the instace of Process class !" << endl;
        return -1;
    } // when casting returns nullptr
}

// returns the unique Id of the process
int Process::getId()
{
    return id;
}

// returns the time when the process was initialized
int Process::getArrivalTime()
{
    return arrivalTime;
}

// returns the total bursts presents in the process including I/O and CPU
int Process::getTotalBurstsTime()
{
    return totalBurstsTime;
}

// restirns exit time
int Process::getExitTime()
{
    return exitTime;
}

// returns wait time
int Process::getWaitTime()
{
    return waitTime;
}

// add burst with the int value in the queue of cpu
void Process::addCPUBurst(int value)
{
    Burst *newBurst = new Burst(value);
    cpuQueue->enqueue(newBurst);
}

// remove the burst from the cpu queue
void Process::removeCPUBurst()
{
    cpuQueue->dequeue();
}

//add burst in I/O queue
void Process::addIOBurst(int value)
{
    Burst *newBurst = new Burst(value);
    ioQueue->enqueue(newBurst);
}

// remove burst from the I/O
void Process::removeIOBurst()
{
    ioQueue->dequeue();
}

// retrieve the data from cpu queue's first element
int Process::getCpuBurst()
{
    // applying safe dynamic casting
    Burst *topBurst = dynamic_cast<Burst *>(cpuQueue->getFront());

    if (topBurst != nullptr)
    {
        return topBurst->getIntValue();
    }

    return 0;
}

//set the value given in the parameter as a top element of the queue
void Process::setCpuBurst(int newValue)
{
    Burst *topBurst = dynamic_cast<Burst *>(cpuQueue->getFront());

    //applying safe dynamic casting
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

//set exit time and wait time helpful during creating exit event for the process
void Process::setExitTime(int newTime)
{
    exitTime = newTime;
}

void Process::setWaitTime(int newTime)
{
    waitTime = newTime;
}

//increment the total burst time
void Process::incrementBurstTime(int newValue)
{
    totalBurstsTime = totalBurstsTime + newValue;
}

//prints all the info related to the process
void Process::print()
{

    cout << "    " << getId() << "    "
         << "    " << getArrivalTime() << "    "
         << "        " << getExitTime() << "    "
         << "        " << getWaitTime() << endl;
}
