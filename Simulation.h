/*--------------------------------------------------------------

    File       : Simulation.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the simulation class


-------------------------------------------------------------------*/

#pragma once // prevents multiple includes of header file

// useful for file reading

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

// forward referenceing as required
class Process;
class Queue;
class PriorityQueue;
class Event;

using namespace std;

class Simulation
{
private:
	// Queues for CPU and IO, and priority queues for Events
	PriorityQueue *eventList;
	Queue *processList;
	Queue *cpuForSim;
	Queue *ioForSim;

	ifstream fileRead; // for file reading

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

	// to check if the queues are empty or not
	bool isProcessListEmpty();
	bool isCPUEmpty();
	bool isIOEmpty();

	// add elements in the respective queues
	void addEvent(Event *);
	void addToProcessList(Process *);
	void addProcessToCPU(Process *);
	void addProcessToIO(Process *);

	// to getter methods
	int getMaxTimeQ();
	int currentTime();

	//set arrival event
	void setArrival();
	void setTime(int);
	void incrementTime(int);

	//remove and retrieve elements from the queue
	Process *removeProcessFromCPU();
	Process *getCPUFront();
	Process *removeProcessFromIO();
	Process *getIOFront();

}; // class Simulation
