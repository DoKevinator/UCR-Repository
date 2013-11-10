#Assignment #5 Makefile

#macros
COMPILE = g++
#FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -ggdb
OBJS = planet.o mars.o earth.o neptune.o

all: test_planets planet.o earth.o mars.o neptune.o my_shell 

test_planets: test_planets.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o test_planets test_planets.cc $(OBJS)

earth.o: earth.h earth.cc
	$(COMPILE) $(FLAGS) -c earth.cc

mars.o: mars.h mars.cc
	$(COMPILE) $(FLAGS) -c mars.cc

neptune.o: neptune.h neptune.cc
	$(COMPILE) $(FLAGS) -c neptune.cc

my_shell: my_shell.cc
	$(COMPILE) $(FLAGS) -o my_shell my_shell.cc

clean:
	rm -rf *~ *.o *.gch a.out test_planets my_shell a.out.dSYM

tar:
	tar -czvf hw5.tgz typescript test_planets.cc planet.h planet.cc earth.h earth.cc mars.h mars.cc my_shell.cc Makefile

debug_test_planets: test_planets
	$(COMPILE) $(DEBUG) -o test_planets test_planets.cc planet.cc earth.cc mars.cc neptune.cc

debug_my_shell: my_shell
	$(COMPILE) $(DEBUG) -o my_shell my_shell.cc

strip:
	strip -S my_shell

print:
	cat String.cc