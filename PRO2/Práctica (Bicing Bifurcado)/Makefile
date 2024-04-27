OPCIONS =-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -fno-extended-identifiers -Wno-sign-compare -std=c++11

program.exe: program.o Bici.o Cjt_bicis.o Estacion.o Cjt_estaciones.o
	g++ -o program.exe program.o Bici.o Cjt_bicis.o Estacion.o Cjt_estaciones.o

Bici.o:  Bici.cc Bici.hh
	g++ -c Bici.cc $(OPCIONS)

Cjt_bicis.o:  Cjt_bicis.cc Cjt_bicis.hh
	g++ -c Cjt_bicis.cc $(OPCIONS)

Estacion.o:  Estacion.cc Estacion.hh
	g++ -c Estacion.cc $(OPCIONS)

Cjt_estaciones.o:  Cjt_estaciones.cc Cjt_estaciones.hh
	g++ -c Cjt_estaciones.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe

practica.tar:
	tar -cvf practica.tar Bici.hh Cjt_bicis.hh Estacion.hh Cjt_estaciones.hh Bici.cc Cjt_bicis.cc Estacion.cc Cjt_estaciones.cc program.cc 'Justificació de mètodes (Bicing Bifurcado) - Mateus Grandolfi Albuquerque'.pdf html.zip Makefile