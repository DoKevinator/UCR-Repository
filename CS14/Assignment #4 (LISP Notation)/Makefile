#LISP Notation Assn4 makefile

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = syntaxtree.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

syntaxtree.o: syntaxtree.cpp syntaxtree.h
	$(COMPILE) $(FLAGS) -c syntaxtree.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn4.tgz *.cpp *.h Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)