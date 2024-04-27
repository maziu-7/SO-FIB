#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

void actualitzar(Cjt_estudiants &c1, const Cjt_estudiants &c2) {
	int N = c1.mida();
	for(int i = 0; i < N; ++i) {
		Estudiant e1 = c1.consultar_iessim(i+1);
		Estudiant e2 = c2.consultar_iessim(i+1);
		if(e2.te_nota()) {
			if(e1.te_nota()) {
				if(e1.consultar_nota() < e2.consultar_nota()) {
					c1.modificar_iessim(i+1,e2);
				}
			}
			else {
				c1.modificar_iessim(i+1,e2);
			}
		}
	}
}

int main() {
	Cjt_estudiants c1, c2;
	c1.llegir();
	c2.llegir();
	actualitzar(c1, c2);
	c1.escriure();
}