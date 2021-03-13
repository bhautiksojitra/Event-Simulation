/*--------------------------------------------------------------

    File       : CompleteCpu.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  An Event that handles the process that complete its work on CPU  

-------------------------------------------------------------------*/
#include "CompleteCpu.h"

#include "Process.h"
#include "Simulation.h"

#include "StartIO.h"
#include "StartCpu.h"
#include "Exit.h"

#include <iostream>

using namespace std;

//constuctor - Indirectly calls the constructor of Event(Super class)
CompleteCpu::CompleteCpu(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim) {}

//Main maethod for this Event
void CompleteCpu::handleEvent()
{
    //Pointers to the the process and simulator
    Process *theProcess = this->getProcess();
    Simulation *theSim = this->getSimulation();

    //remove process from the CPU Queue(Because the work is done)
    theSim->removeProcessFromCPU();
    theProcess->removeCPUBurst(); // Remove the particular "work" aka Burst from the process

    //If the process has no more I/O Bursts to compute
    if (theProcess->getIOBurst() == 0)
    {
        //Create An Exit Event for this Process.
        Exit *newEvent = new Exit(this->getTime(), theProcess, theSim);
        theSim->addEvent(newEvent);
    }
    else if (theProcess->getIOBurst() != 0)
    {

        //If the Process has more Burst to compute
        if (theSim->isIOEmpty())
        {
            //Initialize the StartI/O Event Based on the current state of I/O Queue
            StartIO *newEvent = new StartIO(this->getTime(), theProcess, theSim);
            theSim->addEvent(newEvent);
            theSim->addProcessToIO(theProcess);
        }
        else if (!theSim->isIOEmpty())
        {
            theSim->addProcessToIO(theProcess);
        }
    }

    //Initialize the CPU for the next process in the queue
    if (!theSim->isCPUEmpty())
    {
        StartCpu *newEvent = new StartCpu(this->getTime(), theSim->getCPUFront(), theSim);
        theSim->addEvent(newEvent);
    }
}

//Prints the event Info.
void CompleteCpu::printEvent()
{
    cout << "Time : " << Event::getTime() << " Process : " << this->getProcess()->getId()
         << " completes CPU burst. Queueing for I/O." << endl;
}