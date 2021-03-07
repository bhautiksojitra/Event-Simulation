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
	isBurstEnough = false;
}

void StartCpu::handleEvent()
{
	Process *theProcess = this->getProcess();
	Simulation *theSim = this->getSimulation();

	if ((theProcess->getCpuBurst()) <= (theSim->getMaxTimeQ()))
	{

		isBurstEnough = true;

		theSim->incrementTime(theProcess->getCpuBurst());
		CompleteCpu *newEvent = new CompleteCpu(theSim->currentTime(), theProcess, theSim);
		theSim->addEvent(newEvent);
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

	if (isBurstEnough)
	{
		cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
			 << "  begins CPU burst (will complete all " << currProcess->getCpuBurst() << " remaining units). " << endl;
	}
	else
	{
		cout << "Time : " << this->getTime() << " Process : " << currProcess->getId()
			 << "  begins CPU burst (will time out; needs " << currProcess->getCpuBurst() << " units total)." << endl;
	}
}
