#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "Timeout.h"
#include <string>

using namespace std;

Arrival::Arrival(int theArrivalTime, Process *theProcess, Simulation *theSim)
    : Event(theArrivalTime, theProcess, theSim)
{
    statusCPU = false;
}

void Arrival::handleEvent()
{

    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    if (currSim->isCPUEmpty())
    {
        statusCPU = true;

        StartCpu *newEvent = new StartCpu(this->getTime(), currProcess, currSim);
        currSim->addEvent(newEvent);

        currSim->addProcessToCPU(currProcess);
    }
    else
    {
        currSim->addProcessToCPU(currProcess);
    }

    currSim->setArrival();
}

int Arrival::compareTo(ListItem *other)
{
    Event *castEvent = dynamic_cast<Event *>(other);
    int boolean = 0;

    if (Timeout *temp = dynamic_cast<Timeout *>(castEvent))
    {
        if (this->getTime() <= castEvent->getTime())
        {
            boolean = 1;
        }
    }
    else
    {
        boolean = Event::compareTo(other);
    }
    return boolean;
}

void Arrival::printEvent()
{
    if (statusCPU)
    {
        cout << "Time : " << this->getTime() << " Process " << this->getProcess()->getId()
             << " arrives in system: CPU is free (process begins execution)." << endl;
    }
    else
    {
        cout << "Time : " << this->getTime() << " Process " << this->getProcess()->getId()
             << " arrives in system: CPU is busy (process will be queued)." << endl;
    }
}
