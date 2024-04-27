#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

int main() {
	Cjt_estudiants c;
	c.llegir();
	int op;
	while(cin >> op and op != -6) {
		if(op == -1) {
			//afegir
			Estudiant e;
			e.llegir();
			if(c.existeix_estudiant(e.consultar_DNI())) {
				cout << "el estudiante " << e.consultar_DNI() << " ya estaba" << endl << endl;
			}
			else if(c.mida() == Cjt_estudiants::mida_maxima()){
				cout << "el conjunto esta lleno" << endl << endl;
			}
			else c.afegir_estudiant(e);
		}
		else if(op == -2) {
			//consultar_nota
			int dni;
			cin >> dni;
			if(c.existeix_estudiant(dni)) {
				Estudiant e = c.consultar_estudiant(dni);
				if(e.te_nota()) 
					cout << "el estudiante " << dni << " tiene nota " << e.consultar_nota() << endl << endl;
				else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
			}
			else cout << "el estudiante " << dni << " no esta" << endl << endl;
		}
		else if(op == -3) {
			//modificar nota
			Estudiant e;
			e.llegir();
			if(c.existeix_estudiant(e.consultar_DNI())) {
				c.modificar_estudiant(e);
			}
			else {
				cout << "el estudiante " << e.consultar_DNI() << " no esta" << endl << endl;
			}
		}
		else if(op == -4) {
			//redondear notas
			for(int i = 0; i < c.mida(); ++i) {
				Estudiant e = c.consultar_iessim(i+1);
				if(e.te_nota()) {
					double nota = redondear(e.consultar_nota());
					e.modificar_nota(nota);
					c.modificar_estudiant(e);
				}
			}
		}
		else if(op == -5) {
			//escriure conjunt
			c.escriure();
			cout << endl;
		}
	}
}