#include "StartIO.h"
#include "Process.h"
#include "Simulation.h"
#include "CompleteIO.h"
#include "Timeout.h"
#include <iostream>
using namespace std;

StartIO::StartIO(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

void StartIO::handleEvent()
{
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    int completeIOTime = currSim->currentTime() + currProcess->getIOBurst();

    CompleteIO *newEvent = new CompleteIO(completeIOTime, currProcess, currSim);
    currSim->addEvent(newEvent);
}

void StartIO::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
         << " begins I/O burst of length " << currProcess->getIOBurst() << endl;
}