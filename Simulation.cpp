#include "Simulation.h"
#include "Process.h"

using namespace std;

Simulation::Simulation()
{
    eventList = new PriorityQueue();
    cpuForSim = new Queue();
    ioForSim = new Queue();
    processList = new Queue();
    newId = 1;
    currTime = 0;
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
        Event *currentEvent = dynamic_cast<Event *>(eventList->extractMax());
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
            }
            else
            {
                bursts = -bursts;
                newProcess->addIOBurst(bursts);
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

//change it
void Simulation::summary()
{
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