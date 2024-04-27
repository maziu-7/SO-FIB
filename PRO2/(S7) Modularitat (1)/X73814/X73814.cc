#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<Estudiant> v(N);
    for (int i = 0; i < N; ++i) {
        v[i].llegir();
    }

    vector<Estudiant> salida;
    salida.push_back(v[0]);
    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i].consultar_DNI() == salida[j].consultar_DNI()) {
            if (v[i].te_nota()) {
                if (salida[i].te_nota()) {
                    if (v[i].consultar_nota() > salida[i].consultar_nota()) {
                        salida[j].modificar_nota(v[i].consultar_nota());
                    }
                }
                else salida[j].afegir_nota(v[i].consultar_nota());
            }
        }
        else {
            salida.push_back(v[i]);
            ++j;
        }
    }

    for (int i = 0; i < salida.size(); ++i) {
        salida[i].escriure();
    }
    
    sortida.push_back(e);

    for(int i = 0; i < sortida.size(); ++i) {
		sortida[i].escriure();
	}
}