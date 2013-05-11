#English-Translator makefile

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = map.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

map.o: map.cpp map.h
	$(COMPILE) $(FLAGS) -c map.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn3.tgz *.cpp *.h *.txt Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)