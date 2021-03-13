/*--------------------------------------------------------------

    File       : Event.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  SUPER CLASS OF EVENTS (Holds All the events together through sub classes ) 

-------------------------------------------------------------------*/

#include "Event.h"

//Header files included to check the instances of those classes in compareTo method
#include "Process.h"
#include "Arrival.h"
#include "Timeout.h"

#include <iostream>
using namespace std;

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	: eventTime(theTime), process(theProcess), sim(theSim) {}

/*Overridden method of ListItem class 
	- Compare 2  Objects based on Time they are created and the Id.
	- Determine the priority in PriorityQueue 
*/
int Event::compareTo(ListItem *other)
{
	//return value of this method
	int returnValue = 0;

	//Casting ListItem to Event to compare it with other events
	Event *castEvent = dynamic_cast<Event *>(other);

	//checking the return value of dynamic casting
	if (castEvent != nullptr)
	{
		// if the event initializes eariler then it should have higher prioirity
		if (castEvent->getTime() > this->getTime())
		{
			returnValue = 1;
		}
		// If both occurs at the same time
		else if (castEvent->getTime() == this->getTime())
		{

			// comparison between timeout and arrival - arrival gets the priority
			if (dynamic_cast<Arrival *>(this) && dynamic_cast<Timeout *>(castEvent))
			{
				returnValue = 1;
			}
			else if (dynamic_cast<Timeout *>(this) && dynamic_cast<Arrival *>(castEvent))
			{
				returnValue = 0;
			}
			else if (this->getProcess()->getId() < castEvent->getProcess()->getId())
			{
				returnValue = 1;
			} // if not arrival and timeout then check based on the processID.
		}
	}

	return returnValue; // returns the result
}

Event::Event() {}

// Polymorphic method of Event - doesn't call this version because Event is Abstract
void Event::printEvent()
{
	cout << "Something went wrong ! didn't call the overridden method" << endl;
}

//some getter methods to get the pointers as required in the sub classes

int Event::getTime()
{
	return eventTime;
}

Process *Event::getProcess()
{
	return process;
}

Simulation *Event::getSimulation()
{
	return sim;
}
