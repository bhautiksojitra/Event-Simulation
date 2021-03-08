#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "PriorityQueue.h"
#include "Queue.h"
class Process;

#include "Arrival.h"

using namespace std;

class Simulation
{
private:
	// you will need to add fields
	// including: Queues for CPU and IO, and priority queues for Events
	PriorityQueue *eventList;
	Queue *processList;
	Queue *cpuForProcess;
	Queue *ioForProcess;
	Queue *cpuForSim;
	Queue *ioForSim;
	ifstream fileRead;
	int newId;
	int maxCpuBurst;
	int currTime;

public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods
	bool isProcessListEmpty();
	bool isCPUEmpty();
	bool isIOEmpty();

	void addEvent(Event *);
	void addToProcessList(Process *);
	void setArrival();
	int currentTime();
	void setTime(int);
	int getMaxTimeQ();
	void incrementTime(int);
	void addProcessToCPU(Process *);
	void addProcessToIO(Process *);
	Process *removeProcessFromCPU();
	Process *getCPUFront();

	Process *removeProcessFromIO();
	Process *getIOFront();

}; // class Simulation
