#pragma once

#include "CompleteIO.h"
#include "Process.h"
#include "Simulation.h"
#include "StartIO.h"
#include "StartCpu.h"

#include <iostream>

using namespace std;

CompleteIO::CompleteIO(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

void CompleteIO::handleEvent()
{
    Process *theProcess = this->getProcess();
    Simulation *theSim = this->getSimulation();

    theSim->removeProcessFromIO();
    theProcess->removeIOBurst();

    if (!theSim->isIOEmpty())
    {
        StartIO *newEvent = new StartIO(theSim->currentTime(), theSim->getIOFront(), theSim);
        theSim->addEvent(newEvent);
    }

    if (theSim->isCPUEmpty() && theProcess->getCpuBurst() != 0)
    {
        StartCpu *newEvent = new StartCpu(theSim->currentTime(), theProcess, theSim);
        theSim->addEvent(newEvent);
        theSim->addProcessToCPU(theProcess);
    }
    else if (!theSim->isCPUEmpty() && theProcess->getCpuBurst() != 0)
    {
        theSim->addProcessToCPU(theProcess);
        StartCpu *newEvent = new StartCpu(theSim->currentTime(), theSim->getCPUFront(), theSim);
        theSim->addEvent(newEvent);
    }
}

void CompleteIO::printEvent()
{
    cout << "Time : " << Event::getTime() << "  Process : " << this->getProcess()->getId()
         << " completes I/O burst. Queueing for CPU." << endl;
}