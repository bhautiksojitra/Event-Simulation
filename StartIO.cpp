#include "StartIO.h"
#include "Process.h"
#include "Simulation.h"
#include "CompleteCpu.h"
#include "Timeout.h"
#include <iostream>
using namespace std;

StartIO::StartIO(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

void StartIO::handleEvent()
{
}

void StartIO::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << " Time : " << this->getTime() << "Process : " << currProcess->getId()
         << "  has done startIO event !" << endl;
}