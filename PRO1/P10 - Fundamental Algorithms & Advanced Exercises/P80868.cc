#include <iostream>
using namespace std;

int nombre_digits(int n) {
	if(n == 0){
		return 0;
	}
	return 1 + nombre_digits(n/10);
}

void punts(int actual, int files, int digits) {
	int puntets = 1 + 2*(files-actual)*(digits+1);
	for(int i = 0; i < puntets; ++i){
		cout << ".";
	}
}

void pre(int fila, int n) {
	cout << n;
	for(int i = 0; i < fila-1; ++i){
		cout << "-" << n;
	}
}

void post(int fila, int n) {
	for(int i = 0; i < fila-1; ++i){
		cout << n << "-";
	}
	cout << n;
}

int main(){
	int n, f;
	cin >> n >> f;
	int digits = nombre_digits(n);
	if(n == 0) digits = 1;
	for(int i = 1; i <= f; ++i) {
		pre(i, n);
		punts(i, f, digits);
		post(i, n);
		cout << endl;
	}
}