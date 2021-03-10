#include "PriorityQueue.h"
#include "Arrival.h"
#include "Process.h"
#include "Simulation.h"
#include "Timeout.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testing getFront() in PriorityQueue")
{
    PriorityQueue *newQueue = new PriorityQueue();
    Simulation *sim = new Simulation();

    Arrival *newEvent1 = new Arrival(10, new Process(10, 1), sim);
    Arrival *newEvent2 = new Arrival(20, new Process(20, 2), sim);

    REQUIRE(newQueue->getFront() == nullptr);

    newQueue->enqueue(newEvent1);
    REQUIRE(newQueue->getFront() == newEvent1);

    newQueue->enqueue(newEvent2);
    REQUIRE(newQueue->getFront() == newEvent1);
    REQUIRE(newQueue->getFront() != newEvent2);
}
TEST_CASE("Testing isEmpty() in PriorityQueue")
{
    PriorityQueue *newQueue = new PriorityQueue();
    Simulation *sim = new Simulation();

    Arrival *newEvent1 = new Arrival(10, new Process(10, 1), sim);
    Arrival *newEvent2 = new Arrival(20, new Process(20, 2), sim);

    REQUIRE(newQueue->isEmpty());
    newQueue->enqueue(newEvent1);
    REQUIRE(!newQueue->isEmpty());

    newQueue->dequeue();
    REQUIRE(newQueue->isEmpty());
}

TEST_CASE("Testing getSize() in PriorityQueue")
{
    PriorityQueue *newQueue = new PriorityQueue();
    Simulation *sim = new Simulation();

    Arrival *newEvent1 = new Arrival(10, new Process(10, 1), sim);
    Arrival *newEvent2 = new Arrival(20, new Process(20, 2), sim);

    newQueue->enqueue(newEvent1);
    REQUIRE(newQueue->getSize() == 1);

    newQueue->enqueue(newEvent2);
    REQUIRE(newQueue->getSize() == 2);
    REQUIRE(newQueue->getSize() != 1);

    newQueue->dequeue();
    REQUIRE(newQueue->getSize() == 1);
}

TEST_CASE("Testing Enqueue in PriorityQueue")
{
    PriorityQueue *newQueue = new PriorityQueue();
    Simulation *sim = new Simulation();

    Arrival *newEvent1 = new Arrival(10, new Process(10, 1), sim);
    Arrival *newEvent2 = new Arrival(20, new Process(20, 2), sim);

    Timeout *newEvent3 = new Timeout(10, new Process(10, 1), sim);

    Timeout *newEvent4 = new Timeout(5, new Process(15, 3), sim);

    newQueue->enqueue(newEvent1);
    REQUIRE(newQueue->getFront() == newEvent1);

    newQueue->enqueue(newEvent2);
    REQUIRE(newQueue->getFront() == newEvent1);
    REQUIRE(newQueue->getFront() != newEvent2);

    newQueue->enqueue(newEvent3);
    REQUIRE(newQueue->getFront() == newEvent1);
    REQUIRE(newQueue->getFront() != newEvent3);

    newQueue->enqueue(newEvent4);
    REQUIRE(newQueue->getFront() == newEvent4);
    REQUIRE(newQueue->getFront() != newEvent1);
}

TEST_CASE("Testing dequeue in PriorityQueue")
{
    PriorityQueue *newQueue = new PriorityQueue();
    Simulation *sim = new Simulation();

    Arrival *newEvent1 = new Arrival(10, new Process(10, 1), sim);
    Arrival *newEvent2 = new Arrival(10, new Process(10, 1), sim);

    Timeout *newEvent3 = new Timeout(10, new Process(10, 1), sim);
    Timeout *newEvent4 = new Timeout(15, new Process(15, 1), sim);

    newQueue->enqueue(newEvent1);
    newQueue->enqueue(newEvent2);
    newQueue->enqueue(newEvent3);
    newQueue->enqueue(newEvent4);

    REQUIRE(newQueue->dequeue() == newEvent1);

    REQUIRE(newQueue->dequeue() == newEvent2);

    REQUIRE(newQueue->dequeue() == newEvent3);

    REQUIRE(newQueue->dequeue() == newEvent4);
}
