#pragma once

#include "Timeout.h"
#include "Process.h"
#include "Simulation.h"
#include "StartCpu.h"

using namespace std;

Timeout::Timeout(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
    remainingBurst = 0;
}

void Timeout::handleEvent()
{
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();
    int currBurst = currProcess->getCpuBurst();
    int maxTime = currSim->getMaxTimeQ();

    Process *newVersion = currSim->removeProcessFromCPU();

    newVersion->removeCPUBurst();
    if (maxTime > currBurst)
    {
        newVersion->addCPUBurst(maxTime - currBurst);
        remainingBurst = maxTime - currBurst;
    }
    else
    {
        newVersion->addCPUBurst(currBurst - maxTime);
        remainingBurst = currBurst - maxTime;
    }

    currSim->addProcessToCPU(newVersion);

    if (!currSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(currSim->currentTime(), currSim->getCPUFront(), currSim);
        currSim->addEvent(newEvent);
    }
}

void Timeout::printEvent()
{
    cout << "Time : " << Event::getTime() << " Process : " << this->getProcess()->getId()
         << " times out (needs " << remainingBurst << " units more)." << endl;
}