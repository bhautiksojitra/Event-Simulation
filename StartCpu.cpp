
#include "StartCpu.h"
#include "Process.h"
#include "Simulation.h"
#include "CompleteCpu.h"
#include "Timeout.h"
#include <iostream>
using namespace std;

StartCpu::StartCpu(int theTime, Process *theProcess, Simulation *theSim)
	: Event(theTime, theProcess, theSim)
{
}

void StartCpu::handleEvent()
{
	Process *theProcess = this->getProcess();
	Simulation *theSim = this->getSimulation();
	if ((theProcess->getCpuBurst()) <= (theSim->getMaxTimeQ()))
	{
		theSim->incrementTime(theProcess->getCpuBurst());
		CompleteCpu *newEvent = new CompleteCpu(theSim->currentTime(), theProcess, theSim);
		this->getSimulation()->addEvent(newEvent);
	}
	else
	{
		theSim->incrementTime(theSim->getMaxTimeQ());
		Timeout *newEvent = new Timeout(theSim->currentTime(), theProcess, theSim);
		theSim->addEvent(newEvent);
	}
}

void StartCpu::printEvent()
{
	Process *currProcess = this->getProcess();
	cout << " Time : " << this->getTime() << "Process : " << currProcess->getId()
		 << "  has done startCpu event !" << endl;
}
