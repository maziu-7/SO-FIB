#include <iostream>
using namespace std;

int main() {
    char l;
    bool repeated = false;
    int pos = -1; //cuando hagamos el primer cin >> c, pos = 0,
    int a = 0;    //ya que la cadena está indexada a 0. 
    int b = 0;
    int c = 0;
    int d = 0;    //un contador para cada letra posible

    while (not repeated) {
        cin >> l;
        if (l == 'a') {
            ++a;
            repeated = a == 2;
        }
        else if (l == 'b') {
            ++b;
            repeated = b == 2;
        }
        else if (l == 'c') {
            ++c;
            repeated = c == 2;
        }
        else if (l == 'd') {
            ++d;
            repeated = d == 2;
        }
        /*
        Para cada caso, si el contador llega a 2 es porque hay una letra
        repetida. Se acaba el bucle ya que el bool se vuelve true y ya no
        nos interesa analizar el resto de la secuencia.
        */
        ++pos;
    }
    cout << l << ' ' << pos << endl;
}