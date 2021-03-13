/*--------------------------------------------------------------

    File       : StartCpu.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Event that initializes the Burst in the Cpu 


-------------------------------------------------------------------*/

#include "StartCpu.h"

#include "Process.h"
#include "Simulation.h"

#include "CompleteCpu.h"
#include "Timeout.h"

#include <iostream>
using namespace std;

//constructor - Indirectly  call the constructor of the Event class
StartCpu::StartCpu(int theTime, Process *theProcess, Simulation *theSim)
	: Event(theTime, theProcess, theSim)
{
}

//Handles the event - overridden method
void StartCpu::handleEvent()
{

	//pointers to the Process and Simulation class
	Process *theProcess = this->getProcess();
	Simulation *theSim = this->getSimulation();

	// check if the burst is less than TimeQuantam for cpu
	if ((theProcess->getCpuBurst()) <= (theSim->getMaxTimeQ()))
	{
		// set the time for completeCpu event and Initializes the event
		int completeCpuTime = theSim->currentTime() + theProcess->getCpuBurst();
		CompleteCpu *newEvent = new CompleteCpu(completeCpuTime, theProcess, theSim);
		theSim->addEvent(newEvent);
	}
	else
	{

		//set time for timeout event and adds that event in the list
		int timeOutTime = theSim->currentTime() + theSim->getMaxTimeQ();
		Timeout *newEvent = new Timeout(timeOutTime, theProcess, theSim);
		theSim->addEvent(newEvent);
	}
}

// Prints the info based on the event called in handle event
void StartCpu::printEvent()
{
	Process *currProcess = this->getProcess();

	if ((currProcess->getCpuBurst()) <= (this->getSimulation()->getMaxTimeQ()))
	{
		cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
			 << " begins CPU burst (will complete all " << currProcess->getCpuBurst() << " remaining units). " << endl;
	}
	else
	{
		cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
			 << " begins CPU burst (will time out; needs " << currProcess->getCpuBurst() << " units total)." << endl;
	}
}
