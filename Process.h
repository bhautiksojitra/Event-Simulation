#pragma once
class Queue;
class Burst;
#include "ListItem.h"

class Process : public ListItem
{
private:
    int arrivalTime;
    int exitTime;
    int totalBurstsTime;
    int waitTime;
    int id;
    Queue *cpuQueue;
    Queue *ioQueue;

public:
    Process(int, int);
    int compareTo(ListItem *other);
    int getId();
    int getArrivalTime();

    int getTotalBurstsTime();
    int getExitTime();
    int getWaitTime();

    int getCpuBurst();
    int getIOBurst();

    void addCPUBurst(int);
    void addIOBurst(int);
    void setExitTime(int);

    void removeIOBurst();
    void removeCPUBurst();

    void incrementBurstTime(int);
    void setWaitTime(int);

    void print();

   
};