all: Main Test clean

CC=clang++
CFLAGS=--std=c++11

objects = ParentQueue.o Exit.o CompleteIO.o StartIO.o Timeout.o CompleteCpu.o ListItem.o Event.o  StartCpu.o Simulation.o Queue.o PriorityQueue.o Node.o Process.o  Arrival.o Burst.o  

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
