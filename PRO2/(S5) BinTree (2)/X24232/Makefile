#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#With -O2 an error occurs, we don't know why.
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o removeAll.o 
	g++ -o program.exe program.o removeAll.o 

program.o: program.cc removeAll.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

removeAll.o: removeAll.cc removeAll.hh BinTree.hh
	g++ -c removeAll.cc $(OPCIONS)

clean:
	rm *.o *.exe
