#include "Simulation.h"
#include "Process.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Arrival.h"

using namespace std;

Simulation::Simulation()
{
    eventList = new PriorityQueue();
    cpuForSim = new Queue();
    ioForSim = new Queue();
    processList = new Queue();
    newId = 1;
    currTime = 0;
    sum1 = 0;
    sum2 = 0;
}

void Simulation::runSimulation(char *fileName)
{

    fileRead.open(fileName);

    string line;

    getline(fileRead, line);

    istringstream iss(line);

    iss >> maxCpuBurst;

    setArrival();
    while (!(eventList->isEmpty()))
    {
        Event *currentEvent = dynamic_cast<Event *>(eventList->dequeue());
        this->setTime(currentEvent->getTime());
        currentEvent->printEvent();
        currentEvent->handleEvent();
    }

    fileRead.close();
}

void Simulation::setArrival()
{

    int arrivalTime;
    int bursts;

    string newLine;

    if (getline(fileRead, newLine))
    {

        istringstream iss(newLine);

        iss >> arrivalTime;

        Process *newProcess = new Process(arrivalTime, newId++);

        while (iss >> bursts)
        {
            if (bursts >= 0)
            {
                newProcess->addCPUBurst(bursts);
                newProcess->incrementBurstTime(bursts);
                sum1 += bursts;
            }
            else
            {
                bursts = -bursts;
                newProcess->addIOBurst(bursts);
                newProcess->incrementBurstTime(bursts);
                sum2 += bursts;
            }
        }

        Arrival *newEvent = new Arrival(arrivalTime, newProcess, this);

        this->addEvent(newEvent);
        this->addToProcessList(newProcess);
    }
}

bool Simulation::isProcessListEmpty()
{
    return processList->isEmpty();
}

bool Simulation::isCPUEmpty()
{
    return cpuForSim->isEmpty();
}

bool Simulation::isIOEmpty()
{
    return ioForSim->isEmpty();
}

void Simulation::addEvent(Event *newEvent)
{
    eventList->enqueue(newEvent);
}

void Simulation::addToProcessList(Process *newProcess)
{
    processList->enqueue(newProcess);
}

void Simulation::summary()
{
    cout << " sum1 : " << sum1 << endl;
    cout << " sum2 : " << sum2 << endl;
    cout << " Process "
         << " ArrivalTime "
         << " ExitTime "
         << " WaitTime " << endl;
    cout << "-------------------------------------------------------------" << endl;
    while (!isProcessListEmpty())
    {
        Process *theProcess = dynamic_cast<Process *>(processList->dequeue());
        theProcess->print();
    }
}

int Simulation::currentTime()
{
    return currTime;
}

void Simulation::setTime(int newTime)
{
    currTime = newTime;
}

int Simulation::getMaxTimeQ()
{
    return maxCpuBurst;
}

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

Process *Simulation::getCPUFront()
{
    return dynamic_cast<Process *>(cpuForSim->getFront());
}

Process *Simulation::removeProcessFromIO()
{
    return dynamic_cast<Process *>(ioForSim->dequeue());
}

Process *Simulation::getIOFront()
{
    return dynamic_cast<Process *>(ioForSim->getFront());
}