#Assignment #3 Makefile

#macros
COMPILE = g++
#FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -ggdb
OBJS = String.o

testString: testString.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o testString testString.cc $(OBJS)

String.o: String.h String.cc
	$(COMPILE) $(FLAGS) -c String.cc

myio: myio.cc
	$(COMPILE) $(FLAGS) -o myio myio.cc

myfork: myfork.cc 
	$(COMPILE) $(FLAGS) -o myfork myfork.cc 

Timer.o: Timer.h 
	$(COMPILE) $(FLAGS) -c Timer.h

clean:
	rm -rf *~ *.o *.gch a.out String myio myfork testString a.out.dSYM

tar:
	tar -czvf hw3.tgz typescript String.h String.cc testString.cc myio.cc myfork.cc Timer.h vi.txt Makefile

debug_testString: testString
	$(COMPILE) $(DEBUG) -o testString testString.cc String.cc

debug_myio: myio
	$(COMPILE) $(DEBUG) -o myio myio.cc

debug_myfork: myfork
	$(COMPILE) $(DEBUG) -o myfork myfork.cc











