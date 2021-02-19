#include "Event.h"

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim) 
	 :eventTime(theTime), process(theProcess), sim (theSim) {}


int Event::compareTo(ListItem *other){
	return -1; // you should implement this method.
}

