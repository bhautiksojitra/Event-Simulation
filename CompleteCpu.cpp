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

    if (theProcess->getIOBurst() != 0)
    {
        StartIO *newEvent = new StartIO(theSim->currentTime(), theProcess, theSim);
    }
    else
    {
        cout << "exit event should be created" << endl;
    }

    Process *newVersion = theSim->removeProcessFromCPU();

    newVersion->removeCPUBurst();
    theSim->addProcessToCPU(newVersion);

    if (!theSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(theSim->currentTime(), theSim->getCPUFront(), theSim);
        theSim->addEvent(newEvent);
    }
}

void CompleteCpu::printEvent()
{
    cout << "Time : " << Event::getTime() << "  Process :  " << this->getProcess()->getId()
         << " completed Cpu event ! " << endl;
}