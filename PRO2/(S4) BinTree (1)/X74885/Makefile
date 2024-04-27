#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#With -O2 an error occurs, we don't know why.
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o evaluate.o utils.o
	g++ -o program.exe program.o evaluate.o utils.o

program.o: program.cc evaluate.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

evaluate.o: evaluate.cc evaluate.hh BinTree.hh
	g++ -c evaluate.cc $(OPCIONS)

utils.o: utils.cc utils.hh
	g++ -c utils.cc $(OPCIONS)

clean:
	rm *.o *.exe
