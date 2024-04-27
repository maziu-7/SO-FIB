#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#With -O2 an error occurs, we don't know why.
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o reverseTree.o 
	g++ -o program.exe program.o reverseTree.o 

program.o: program.cc reverseTree.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

sumOfTree.o: reverseTree.cc reverse.hh BinTree.hh
	g++ -c reverseTree.cc $(OPCIONS)

clean:
	rm *.o *.exe
