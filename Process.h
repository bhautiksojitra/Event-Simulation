
/*--------------------------------------------------------------

    File       : Process.h
    Author     : Bhautik Sojitra
    Student Id : 7900140
    Course     : COMP 2150
    Assignment : 2

    Purpose    :  Interface for the Process 

-------------------------------------------------------------------*/
#pragma once

class Queue;
class Burst;

#include "ListItem.h"

//sub class for the process class
class Process : public ListItem
{
private:
    int arrivalTime;     // time when the process is initialized
    int exitTime;        // time when the process exited from the system
    int totalBurstsTime; // total bursts present to work
    int waitTime;        // time showing how much the process wait during its entire execution
    int id;              // unique id
    Queue *cpuQueue;     // cpu queue holding all the bursts related to cpu
    Queue *ioQueue;      // io queue holding all the bursts related to io

public:
    Process(int, int); // constructor
    int compareTo(ListItem *other) override;

    //all the required getter methods
    int getId();
    int getArrivalTime();
    int getTotalBurstsTime();
    int getExitTime();
    int getWaitTime();
    int getCpuBurst();
    int getIOBurst();

    //required setter methods
    void setCpuBurst(int);
    void setWaitTime(int);
    void setExitTime(int);
    void incrementBurstTime(int);

    //add and remove elements from the queues
    void addCPUBurst(int);
    void addIOBurst(int);
    void removeIOBurst();
    void removeCPUBurst();

    //prints all the info related to the process
    void print();
};