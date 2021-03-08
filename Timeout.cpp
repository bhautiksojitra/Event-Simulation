#include "Timeout.h"
#include "Process.h"
#include "Simulation.h"
#include "StartCpu.h"

using namespace std;

Timeout::Timeout(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
    remainingBurst = this->getProcess()->getCpuBurst() - this->getSimulation()->getMaxTimeQ();
}

void Timeout::handleEvent()
{
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();
    int currBurst = currProcess->getCpuBurst();
    int maxTime = currSim->getMaxTimeQ();

    Process *newVersion = currSim->removeProcessFromCPU();

    newVersion->removeCPUBurst();

    newVersion->addCPUBurst(currBurst - maxTime);

    currSim->addProcessToCPU(newVersion);

    if (!currSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(this->getTime(), currSim->getCPUFront(), currSim);
        currSim->addEvent(newEvent);
    }
}

int Timeout::compareTo(ListItem *other)
{
    Event *castEvent = dynamic_cast<Event *>(other);
    int boolean = 1;

    if (Arrival *temp = dynamic_cast<Arrival *>(castEvent))
    {
        if (this->getTime() >= castEvent->getTime())
        {
            boolean = 0;
        }
    }
    else
    {
        boolean = Event::compareTo(other);
    }

    return boolean;
}

void Timeout::printEvent()
{
    cout << "Time : " << Event::getTime() << " Process : " << this->getProcess()->getId()
         << " times out (needs " << remainingBurst << " units more)." << endl;
}