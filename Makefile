all: Main Test clean

CC=clang++
CFLAGS=--std=c++11

objects =  Arrival.o Burst.o CompleteCpu.o CompleteIO.o  Event.o Exit.o ListItem.o Node.o ParentQueue.o PriorityQueue.o Process.o  Queue.o StartIO.o  StartCpu.o Simulation.o  Timeout.o

# this rule will build A2 as the executable from the object files
Main: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)
Test: TestClass.o $(objects)	
	$(CC) $(CFLAGS) -o test $< $(objects)

# this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(objects)
	rm -f A2main.o
	rm -f TestClass.o
