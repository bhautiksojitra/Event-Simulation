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

    if (!theSim->isIOEmpty())
    {
        Process *newVersion = theSim->removeProcessFromIO();

        newVersion->removeIOBurst();

        StartIO *newEvent = new StartIO(theSim->currentTime(), theSim->getIOFront(), theSim);
        theSim->addProcessToIO(newVersion);
        theSim->addEvent(newEvent);
    }
}

void CompleteIO::printEvent()
{
    cout << "Time : " << Event::getTime() << "  Process : " << this->getProcess()->getId()
         << " completes I/O burst. Queueing for CPU." << endl;
}