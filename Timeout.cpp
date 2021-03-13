/*--------------------------------------------------------------

    File       : Timeout.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Holds the info of the process when it timeout from the cpu 


-------------------------------------------------------------------*/
#include "Timeout.h"

#include "Process.h"
#include "Simulation.h"
#include "StartCpu.h"

using namespace std;

//constructor - indirectly calls the one in the event class
Timeout::Timeout(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
    remainingBurst = this->getProcess()->getCpuBurst() - this->getSimulation()->getMaxTimeQ();
}

void Timeout::handleEvent()
{
    //Pointers to the required classes
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    int currBurst = currProcess->getCpuBurst();
    int maxTime = currSim->getMaxTimeQ();

    //remove process from the queue
    Process *newVersion = currSim->removeProcessFromCPU();

    //set the new burst as remaining burst for the process
    newVersion->setCpuBurst(currBurst - maxTime);
    currSim->addProcessToCPU(newVersion); // add the new version of the process back to the queue

    //if the cpu is not empty than add startCPU to eventList
    if (!currSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(this->getTime(), currSim->getCPUFront(), currSim);
        currSim->addEvent(newEvent);
    }
}

//prints the info
void Timeout::printEvent()
{
    cout << "Time : " << Event::getTime() << " Process : " << this->getProcess()->getId()
         << " times out (needs " << remainingBurst << " units more)." << endl;
}