#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

bool comp(const Estudiant &e1, const Estudiant &e2) {
	//retorna true si e1 ha d'anar primer que e2
	if(e1.consultar_nota() != e2.consultar_nota()) {
		return e1.consultar_nota() > e2.consultar_nota();
	}
	return e1.consultar_DNI() < e2.consultar_DNI(); 
}

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	vector<bool> seleccionades(N, false);
	int x;
	for(int i = 0; i < S; ++i) {
		cin >> x;
		seleccionades[x-1] = true;
	}
	vector<Estudiant> estudiants(M);
	for(int i = 0; i < M; ++i) {
		double suma = 0;
		estudiants[i].llegir();
		if(seleccionades[0]) suma += estudiants[i].consultar_nota();
		double nota;
		for(int j = 1; j < N; ++j) {
			cin >> nota;
			if(seleccionades[j]) suma += nota;
		}
		estudiants[i].modificar_nota(suma/S);
	}
	sort(estudiants.begin(), estudiants.end(), comp);
	for(int i = 0; i < M; ++i) {
		estudiants[i].escriure();
	}
}