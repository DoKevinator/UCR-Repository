# Game of Risk Makefile

#change all the stuff to risk file stuff.

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi
DEBUG = -g -W -Wall -Werror -ansi
OBJS = graph.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

graph.o: graph.cpp graph.h
	$(COMPILE) $(FLAGS) -c graph.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn5.tgz *.cpp *.h *.graph Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)