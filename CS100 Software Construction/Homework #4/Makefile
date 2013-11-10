#Assignment #4 Makefile

#macros
COMPILE = g++
#FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -ggdb
OBJS = String.o

all: testLinkedString handle_signals my_shell 

testLinkedString: testLinkedString.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o testLinkedString testLinkedString.cc $(OBJS)

String.o: String.h String.cc
	$(COMPILE) $(FLAGS) -c String.cc

handle_signals: handle_signals.cc
	$(COMPILE) $(FLAGS) -o handle_signals handle_signals.cc

my_shell: my_shell.cc
	$(COMPILE) $(FLAGS) -o my_shell my_shell.cc

clean:
	rm -rf *~ *.o *.gch a.out testLinkedString my_shell handle_signals a.out.dSYM

tar:
	tar -czvf hw4.tgz typescript String.h String.cc testLinkedString.cc handle_signals.cc my_shell.cc unix.txt Makefile

debug_testString: testLinkedString
	$(COMPILE) $(DEBUG) -o testString testLinkedString.cc String.cc

debug_my_shell: my_shell
	$(COMPILE) $(DEBUG) -o my_shell my_shell.cc

debug_handle_signals: handle_signals
	$(COMPILE) $(DEBUG) -o handle_signals handle_signals.cc

strip:
	strip -S testLinkedString handle_signals my_shell

print:
	cat String.cc
