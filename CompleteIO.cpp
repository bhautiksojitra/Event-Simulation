/*--------------------------------------------------------------

    File       : CompleteIO.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Manages the completion of the I/O Burst of the Process

-------------------------------------------------------------------*/

#include "CompleteIO.h"

#include "Process.h"
#include "Simulation.h"

#include "StartIO.h"
#include "StartCpu.h"
#include "Exit.h"

#include <iostream>

using namespace std;

//Constructor - Indirectly calls Event Constructor
CompleteIO::CompleteIO(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

//Main Polymorphic method of This class
void CompleteIO::handleEvent()
{
    //Pointers to the class Process and simulation
    Process *theProcess = this->getProcess();
    Simulation *theSim = this->getSimulation();

    //Works same as CompleteCpu class
    theSim->removeProcessFromIO(); // remove process from the queue of I/O
    theProcess->removeIOBurst();   // remove I/O burst of the process

    // Checks if more bursts to compute or not
    if (theProcess->getCpuBurst() == 0)
    {
        //Creates an exit event
        Exit *newEvent = new Exit(this->getTime(), theProcess, theSim);
        theSim->addEvent(newEvent);
    }
    else if (theProcess->getCpuBurst() != 0)
    {

        //Initialize the StartCpu Event based on the current State of the Queue
        //Because CPU is now free to compute another Burst
        if (theSim->isCPUEmpty())
        {
            StartCpu *newEvent = new StartCpu(this->getTime(), theProcess, theSim);
            theSim->addEvent(newEvent);
            theSim->addProcessToCPU(theProcess);
        }
        else if (!theSim->isCPUEmpty())
        {
            theSim->addProcessToCPU(theProcess);
        }
    }

    //Initize the Start I/O Event
    if (!theSim->isIOEmpty())
    {
        StartIO *newEvent = new StartIO(this->getTime(), theSim->getIOFront(), theSim);
        theSim->addEvent(newEvent);
    }
}

//Overridden method prints the INfo of the process
void CompleteIO::printEvent()
{
    cout << "Time : " << Event::getTime() << " Process : " << this->getProcess()->getId()
         << " completes I/O burst. Queueing for CPU." << endl;
}