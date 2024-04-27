#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#With -O2 an error occurs, we don't know why.
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o longestLeftmostPath.o 
	g++ -o program.exe program.o longestLeftmostPath.o 

program.o: program.cc longestLeftmostPath.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

longestLeftmostPath.o: longestLeftmostPath.cc longestLeftmostPath.hh BinTree.hh
	g++ -c longestLeftmostPath.cc $(OPCIONS)

clean:
	rm *.o *.exe
