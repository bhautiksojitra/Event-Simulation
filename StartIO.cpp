/*--------------------------------------------------------------

    File       : StartIO.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :   Event that Manages the initialization of the I/O for the process 


-------------------------------------------------------------------*/
#include "StartIO.h"

#include "Process.h"
#include "Simulation.h"

#include "CompleteIO.h"
#include "Timeout.h"

#include <iostream>
using namespace std;

//constructor - Indiirectly calls the ione in the event
StartIO::StartIO(int theTime, Process *theProcess, Simulation *theSim)
    : Event(theTime, theProcess, theSim)
{
}

//Overridden method - fulfill the main purpose of thsi event
void StartIO::handleEvent()
{
    //Pointers to the process and simulation
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    // set the time to call the completeIO event
    int completeIOTime = currSim->currentTime() + currProcess->getIOBurst();

    //add event in the eventList
    CompleteIO *newEvent = new CompleteIO(completeIOTime, currProcess, currSim);
    currSim->addEvent(newEvent);
}

//prints all the Info
void StartIO::printEvent()
{
    Process *currProcess = this->getProcess();
    cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
         << " begins I/O burst of length " << currProcess->getIOBurst() << endl;
}