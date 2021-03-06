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
}

void Exit::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
         << " Exited the process. " << currProcess->getIOBurst() << endl;
}