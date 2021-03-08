#include "Event.h"
#include "Process.h"
#include <iostream>

using namespace std;

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	: eventTime(theTime), process(theProcess), sim(theSim) {}

int Event::compareTo(ListItem *other)
{
	Event *castEvent = dynamic_cast<Event *>(other);

	if (castEvent->getTime() > this->getTime())
	{
		return 1;
	}
	else if (castEvent->getTime() == this->getTime())
	{
		/*if (this->getProcess()->getId() < castEvent->getProcess()->getId())
		{
			return 1;
		}
		else
		{
			return 0;
		}*/
	return 0;

	
	}
	else
	{
		return -1;
	}
}

Event::Event() {}

void Event::printEvent()
{
	cout << "printing the event class without using polymorphism" << endl;
}

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