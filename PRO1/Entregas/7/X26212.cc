#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c; //filas, columnas
    while (cin >> f >> c) {
        int veces = 0; //el contador se resetea a 0 para cada matriz diferente
        vector<vector<char>> Matriz(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> Matriz[i][j]; //leemos la matriz
        }
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) { //analizamos cada caso posible
                if (Matriz[i][j] == ':' and j < c - 2) {
                    if (Matriz[i][j+1] == '-') {
                        if (Matriz[i][j+2] == ')') ++veces;
                    }
                }
                else if (Matriz[i][j] == '(' and j < c - 2) {
                    if (Matriz[i][j+1] == '-') {
                        if (Matriz[i][j+2] == ':') ++veces;
                    }
                }
                else if (Matriz[i][j] == '"' and i < f - 2) {
                    if (Matriz[i+1][j] == '|') {
                        if (Matriz[i+2][j] == 'v') ++veces;
                    }
                }
                else if (Matriz[i][j] == '^' and i < f - 2) {
                    if (Matriz[i+1][j] == '|') {
                        if (Matriz[i+2][j] == '"') ++veces;
                    }
                }
            }
        }
        cout << veces << endl;
    }
}