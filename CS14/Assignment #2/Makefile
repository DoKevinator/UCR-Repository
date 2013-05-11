#WordLadder makefile

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = wordladder.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

wordladder.o: wordladder.cpp wordladder.h
	$(COMPILE) $(FLAGS) -c wordladder.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn2.tgz *.cpp *.h Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)