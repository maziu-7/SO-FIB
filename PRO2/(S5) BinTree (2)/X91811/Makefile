#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#With -O2 an error occurs, we don't know why.
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sumAtDepthEven.o 
	g++ -o program.exe program.o sumAtDepthEven.o 

program.o: program.cc sumAtDepthEven.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

sumAtDepthEven.o: sumAtDepthEven.cc sumAtDepthEven.hh BinTree.hh
	g++ -c sumAtDepthEven.cc $(OPCIONS)

clean:
	rm *.o *.exe
