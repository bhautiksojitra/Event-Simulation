/*--------------------------------------------------------------

    File       : Event.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  SUPER CLASS OF EVENTS Interface

-------------------------------------------------------------------*/
#pragma once // Prevents multiple includes

#include "ListItem.h"
class Process;
class Simulation;

//Sub class of the ListItem
class Event : public ListItem
{
private:
	int eventTime;
	Process *process;

protected:
	Simulation *sim;

public:
	//default constructor
	Event();

	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, Process *theProcess, Simulation *sim);

	// pure virtual method - to handle the current event when it is removed from the queue.
	virtual void handleEvent() = 0;

	// compareTo - used to order Events.
	int compareTo(ListItem *other);

	int getTime();

	virtual void printEvent(); //prints the info

	Process *getProcess();

	Simulation *getSimulation();

}; // class Event
