
/*--------------------------------------------------------------

    File       : Simulation.cpp
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Central Class for the project 

                    -  read the file
                    -  Initialize the events 
                    -  prints the summary at the end
                    -  manages the priority queue and executes the events and prints them


-------------------------------------------------------------------*/

#include "Simulation.h"
#include "Process.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Arrival.h"

using namespace std;

//constructors
Simulation::Simulation()
{

    // holds so many queues together and manages them
    eventList = new PriorityQueue(); // list for events
    cpuForSim = new Queue();         // queue of processes to be executed in CPU
    ioForSim = new Queue();          //queue of processes for I?O execution
    processList = new Queue();       // List of processes
    newId = 1;                       // Unique Id of the processes
    currTime = 0;                    // current time of the simulator
}

//File reader method
void Simulation::runSimulation(char *fileName)
{

    //opens the file
    fileRead.open(fileName);

    //string to read the line from the file
    string line;

    getline(fileRead, line); // insert the line from the file in string var.

    //stores the first int value as a maxCpuBurst
    istringstream iss(line);
    iss >> maxCpuBurst; // maxCpuBurst means the process can max spend only "maxCpuBurst" time in cpu.

    //set arrival for the first process.
    setArrival();
    //loop until all the events aren't executed
    while (!(eventList->isEmpty()))
    {
        //remove the element with highest priority from the eventList
        Event *currentEvent = dynamic_cast<Event *>(eventList->dequeue());

        //set the current time based on the event that is currently executed
        this->setTime(currentEvent->getTime());

        //first prints the event and handles it which adds another events in the list
        currentEvent->printEvent();
        currentEvent->handleEvent();
    }

    //close the file reading
    fileRead.close();
}

//reads the line from the file as needed and calls arrival event and adds the process in the list
void Simulation::setArrival()
{

    // arrival time to store in the process and initialize the arrival event
    int arrivalTime;
    int bursts;

    //to store the line read fromthe file.
    string newLine;

    // if there is a line to store
    if (getline(fileRead, newLine))
    {

        istringstream iss(newLine);

        iss >> arrivalTime; // store first int value of the line as a time

        // creates the new process
        Process *newProcess = new Process(arrivalTime, newId++);

        // read next int values and store those values as bursts in the process
        while (iss >> bursts)
        {
            //positive means bursts fopr cpu and megative means for IO
            if (bursts >= 0)
            {
                //add to the cpu queue in the process
                newProcess->addCPUBurst(bursts);
                newProcess->incrementBurstTime(bursts);
            }
            else
            {
                //convert it to positive int value
                bursts = -bursts;
                //store it in the IO queue
                newProcess->addIOBurst(bursts);
                newProcess->incrementBurstTime(bursts);
            }
        }

        // creates arrival event and add it to the list
        Arrival *newEvent = new Arrival(arrivalTime, newProcess, this);
        this->addEvent(newEvent);
        this->addToProcessList(newProcess); // add process to the list
    }
}

//prints the summary of the entire simulation at the end
void Simulation::summary()
{
    cout << " Process "
         << " ArrivalTime "
         << " ExitTime "
         << " WaitTime " << endl;
    cout << "-------------------------------------------------------------" << endl;

    // remove each process from the list one by one and prints all the info
    while (!isProcessListEmpty())
    {
        Process *theProcess = dynamic_cast<Process *>(processList->dequeue());
        theProcess->print();
    }
}

// calling isEmpty() methods for various queues to use those in the event sub classes
bool Simulation::isProcessListEmpty()
{
    return processList->isEmpty();
} // ProcessList isEmpty()

bool Simulation::isCPUEmpty()
{
    return cpuForSim->isEmpty();
} // CPU Queue isEmpty()

bool Simulation::isIOEmpty()
{
    return ioForSim->isEmpty();
} // IO Queue isEmpty()

//add Event in the event list
void Simulation::addEvent(Event *newEvent)
{
    eventList->enqueue(newEvent);
}

//add process in the process list
void Simulation::addToProcessList(Process *newProcess)
{
    processList->enqueue(newProcess);
}

//returns the current time
int Simulation::currentTime()
{
    return currTime;
}

//set the current time
void Simulation::setTime(int newTime)
{
    currTime = newTime;
}

//returns max Time Quantam for the cpu
int Simulation::getMaxTimeQ()
{
    return maxCpuBurst;
}

// increments the current time
void Simulation::incrementTime(int addMoreTime)
{
    currTime = currTime + addMoreTime;
}

void Simulation::addProcessToCPU(Process *theProcess)
{
    cpuForSim->enqueue(theProcess);
}

void Simulation::addProcessToIO(Process *theProcess)
{
    ioForSim->enqueue(theProcess);
}

Process *Simulation::removeProcessFromCPU()
{
    return dynamic_cast<Process *>(cpuForSim->dequeue());
}

Process *Simulation::removeProcessFromIO()
{
    return dynamic_cast<Process *>(ioForSim->dequeue());
}

Process *Simulation::getCPUFront()
{
    return dynamic_cast<Process *>(cpuForSim->getFront());
}

Process *Simulation::getIOFront()
{
    return dynamic_cast<Process *>(ioForSim->getFront());
}