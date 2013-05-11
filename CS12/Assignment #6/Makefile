#Bboard makefile

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = bboard.o message.o reply.o topic.o user.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

bboard.o: bboard.cpp bboard.h
	$(COMPILE) $(FLAGS) -c bboard.cpp

message.o: message.cpp message.h
	$(COMPILE) $(FLAGS) -c message.cpp

reply.o: reply.cpp reply.h
	$(COMPILE) $(FLAGS) -c reply.cpp
    
topic.o: topic.cpp topic.h
	$(COMPILE) $(FLAGS) -c topic.cpp
    
user.o: user.cpp user.h
	$(COMPILE) $(FLAGS) -c user.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn6.tgz *.cpp *.h Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)
