#pragma once

#include <fstream>
using namespace std;


class Simulation {
private:
	// you will need to add fields
        // including: Queues for CPU and IO, and priority queues for Events 	
public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName); 

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

};// class Simulation
