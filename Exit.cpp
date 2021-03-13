/*--------------------------------------------------------------

    File       : Exit.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Exit Event (useful when process has done all his work on CPU and I/O)

-------------------------------------------------------------------*/

#include "Exit.h"

#include "Process.h"
#include "Simulation.h"

#include "CompleteCpu.h"
#include "Timeout.h"

#include <iostream>

using namespace std;

//Constructor
Exit::Exit(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

//Overridden method - doesn;t call any another events Just store the summary in the process
void Exit::handleEvent()
{

    Process *theProcess = this->getProcess();

    // Set the Exit time and wait time and prints ot later
    theProcess->setExitTime(this->getTime());
    theProcess->setWaitTime((theProcess->getExitTime() - theProcess->getArrivalTime()) - theProcess->getTotalBurstsTime());
}

//Prints the Info
void Exit::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
         << " All the CPU and I/O Bursts are completed for the process. (Exit) " << endl;
}