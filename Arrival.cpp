#pragma once
#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
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

        currSim->incrementTime(Event::getTime());
        StartCpu *newEvent = new StartCpu(currSim->currentTime(), currProcess, currSim);

        currSim->addProcessToCPU(currProcess);
        currSim->addEvent(newEvent);
    }
    else
    {
        currSim->addProcessToCPU(currProcess);
    }

    sim->setArrival();
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
