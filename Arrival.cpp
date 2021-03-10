/*--------------------------------------------------------------

    File       : Arrival.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose : An Event that handles the arrival of the process in the System.

-------------------------------------------------------------------*/

// Including all required header file.
#include "Arrival.h"
#include "Simulation.h"
#include "StartCpu.h"
#include "Process.h"
#include "Timeout.h"

using namespace std;

// Constructor field But initialise the variables of the super class (Event).
Arrival::Arrival(int theArrivalTime, Process *theProcess, Simulation *theSim)
    : Event(theArrivalTime, theProcess, theSim) {}

// Does all the work in this method
void Arrival::handleEvent()
{

    //Pointers to the process and simulation class which belongs to this arrival
    Process *currProcess = this->getProcess();
    Simulation *currSim = this->getSimulation();

    // Check if the CPU in simulation is empty
    if (currSim->isCPUEmpty())
    {

        // Start another event called StartCpu for this process
        StartCpu *newEvent = new StartCpu(this->getTime(), currProcess, currSim);
        currSim->addEvent(newEvent); // add it to the queue

        currSim->addProcessToCPU(currProcess); // add the process to the cpu queue
    }
    else
    {
        // if the cpu is not empty than add the process to the cpu queue
        currSim->addProcessToCPU(currProcess);
    }

    currSim->setArrival(); // set the arrival of the next process in the simulation.
}

//prints the msg depending on the work done by handle event.
void Arrival::printEvent()
{
    if (this->getSimulation()->isCPUEmpty())
    {
        cout << "Time : " << this->getTime() << " Process " << this->getProcess()->getId()
             << " arrives in system: CPU is free (process begins execution)." << endl;
    }
    else
    {
        cout << "Time : " << this->getTime() << " Process " << this->getProcess()->getId()
             << " arrives in system: CPU is busy (process will be queued)." << endl;
    }
}
