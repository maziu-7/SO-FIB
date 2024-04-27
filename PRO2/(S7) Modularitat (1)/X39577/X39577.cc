#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	vector<bool> seleccionades(N, false);
	int x;
	for(int i = 0; i < S; ++i) {
		cin >> x;
		seleccionades[x-1] = true;
	}

	for(int i = 0; i < M; ++i) {
		double suma = 0;
		Estudiant e;
		e.llegir();
		if(seleccionades[0]) suma += e.consultar_nota();
		double nota;
		for(int j = 1; j < N; ++j) {
			cin >> nota;
			if(seleccionades[j]) suma += nota;
		}
		e.modificar_nota(suma/S);
		e.escriure();
	}
}