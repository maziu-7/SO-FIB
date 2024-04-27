#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c;
    while (cin >> f >> c) {
        vector<vector<char>> Matriz(f, vector<char>(c)); //matriz para los chars del input
        vector<vector<int>> c_parentesis(f, vector<int>(c,0)); //contador de parentesis segun su posicion
        vector<vector<int>> c_guion(f, vector<int>(c,0)); //contador de guiones segun su posicion

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> Matriz[i][j]; //leemos la matriz de chars
        }

        for (int i = f-1; i > 0; --i) {
            for (int j = c-1; j > 0; --j) { //recorremos toda la matriz inversamente
                //actualizamos el contador de parentesis dependiendo de su posicion en la matriz
                if (Matriz[i][j] == ')') ++c_parentesis[i][j];
                if (i != f-1 and j != c-1) c_parentesis[i][j] += c_parentesis[i+1][j] + c_parentesis[i][j+1] - c_parentesis[i+1][j+1];
                else if (i != f-1) c_parentesis[i][j] += c_parentesis[i+1][j];
                else if (j != c-1) c_parentesis[i][j] += c_parentesis[i][j+1];
            }
        }

        for (int i = f-1; i > 0; --i) {
            for (int j = c-1; j > 0; --j) {
                //actualizamos el contador de guiones dependiendo de su posicion en la matriz
                if (Matriz[i][j] == '-' and i != f-1 and j != c-1) c_guion[i][j] += c_parentesis[i+1][j+1];
                c_guion[i-1][j] += c_guion[i][j];
                c_guion[i][j-1] += c_guion[i][j];
                c_guion[i-1][j-1] -= c_guion[i][j];
            }
        }

        //finalmente, comprobamos la posicion de los ':' y si estan en una posicion valida
        //si lo estan, actualizamos la suma final total
        int c_total = 0;
        for (int i = 0; i < f-2; ++i) {
            for (int j = 0; j < c-2; ++j) {
                if (Matriz[i][j] == ':') c_total += c_guion[i+1][j+1];
            }
        }
        cout << c_total << endl;
    }
}