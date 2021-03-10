#include "Exit.h"
#include "Process.h"
#include "Simulation.h"
#include "CompleteCpu.h"
#include "Timeout.h"
#include <iostream>

using namespace std;

Exit::Exit(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

void Exit::handleEvent()
{
    Process *theProcess = this->getProcess();

    theProcess->setExitTime(this->getTime());
    theProcess->setWaitTime((theProcess->getExitTime() - theProcess->getArrivalTime()) - theProcess->getTotalBurstsTime());
}

void Exit::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
         << " All the CPU and I/O Bursts are completed for the process. (Exit) "  << endl;
}