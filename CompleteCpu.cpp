#pragma once

#include "CompleteCpu.h"
#include "Process.h"
#include "Simulation.h"
#include "StartIO.h"
#include "StartCpu.h"

#include <iostream>

using namespace std;

CompleteCpu::CompleteCpu(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

void CompleteCpu::handleEvent()
{
    Process *theProcess = this->getProcess();
    Simulation *theSim = this->getSimulation();

    theSim->removeProcessFromCPU();
    theProcess->removeCPUBurst();

    if (theSim->isIOEmpty() && theProcess->getIOBurst() != 0)
    {
        StartIO *newEvent = new StartIO(theSim->currentTime(), theProcess, theSim);
        theSim->addEvent(newEvent);
        theSim->addProcessToIO(theProcess);
    }
    else if (!theSim->isIOEmpty() && theProcess->getIOBurst() != 0)
    {
        theSim->addProcessToIO(theProcess);
        StartIO *newEvent = new StartIO(theSim->currentTime(), theSim->getIOFront(), theSim);
        theSim->addEvent(newEvent);
    }
    if (!theSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(theSim->currentTime(), theSim->getCPUFront(), theSim);
        theSim->addEvent(newEvent);
    }
}

void CompleteCpu::printEvent()
{
    cout << "Time : " << Event::getTime() << "  Process : " << this->getProcess()->getId()
         << " completes CPU burst. Queueing for I/O." << endl;
}