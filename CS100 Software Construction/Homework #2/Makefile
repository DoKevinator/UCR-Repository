#hw2 makefile

#macros
COMPILE = g++
#FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -ggdb
OBJS = Coins.o



main: main.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o main main.cc $(OBJS)

betterMain: betterMain.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o betterMain betterMain.cc $(OBJS)

bestMain: bestMain.cc $(OBJS)
	$(COMPILE) $(FLAGS) -o bestMain bestMain.cc $(OBJS)

Coins.o: Coins.h Coins.cc
	$(COMPILE) $(FLAGS) -c Coins.cc

my_ls: my_ls.cc
	$(COMPILE) $(FLAGS) -o my_ls my_ls.cc 

clean:
	rm -rf *~ *.o a.out main betterMain bestMain my_ls 

tar:
	tar -czvf hw2.tgz typescript main.cc betterMain.cc bestMain.cc Coins.cc Coins.h my_ls.cc Makefile

debug_my_ls: my_ls
	$(COMPILE) $(DEBUG) -o my_ls my_ls.cc

debug_main: main
	$(COMPILE) $(DEBUG) -o my_ls main.cc Coins.cc

debug_betterMain: betterMain
	$(COMPILE) $(DEBUG) -o my_ls betterMain.cc Coins.cc

debug_bestMain: bestMain
	$(COMPILE) $(DEBUG) -o my_ls bestMain.cc Coins.cc