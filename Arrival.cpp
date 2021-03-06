#pragma once
#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"

//using namespace std;

Arrival::Arrival(int theArrivalTime, Process *theProcess, Simulation *theSim)
    : Event(theArrivalTime, theProcess, theSim)
{
}

void Arrival::handleEvent()
{
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    if (currSim->isCPUEmpty())
    {
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
    cout << "Time : " << this->getTime() << " process " << this->getProcess()->getId() << " arrives in the System." << endl;
}
