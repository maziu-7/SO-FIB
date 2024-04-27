#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

typedef vector<vector<char>> Grafo;
typedef pair<int,int> Coordenadas;
//vector para las 4 direcciones: arriba, der, abajo, izq
const vector<Coordenadas> C = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void read_graph(Grafo& G, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
        }
    }
}

bool in_range(const Grafo& G, pair<int,int> p) {
    //miramos si la posición a la que queremos acceder es válida
    int n = G.size();
    int m = G[0].size();
    return (p.first >= 0 and p.second >= 0 and p.first < n and p.second < m);
    return false;
}

int DFS(Grafo& G, int r, int c) {
    int n = G.size();
    int m = G[0].size();
    //en el pair guardamos las coordenadas x y, en el int guardamos la distancia actual
    queue<pair<pair<int,int>, int>> Q;
    //3 pairs de ints, posición en la q empezamos, posición actual y posición siguiente
    pair<int,int> ini = {r, c};
    --ini.first;
    --ini.second;
    pair<int,int> act;
    pair<int,int> sig;

    //primer elemento de la cola: posición inicial, distancia = 0
    Q.push({ini, 0});
    //como no vamos a volver a esta posición ni nos interesa, la marcamos con una X
    G[ini.first][ini.second] = 'X';

    while (not Q.empty()) {
        act = Q.front().first;
        int d = Q.front().second;
        Q.pop();
        //avanzamos en las 4 direcciones con un for
        for (int i = 0; i < C.size(); ++i) {
            sig.first = act.first + C[i].first; // x siguiente = x actual + dirección x
            sig.second = act.second + C[i].second; // y siguiente = y actual + dirección y
            //comprobamos dos condiciones: vamos a ir a una posición válida y esa posición no es una 'X'
            if (in_range(G, sig) and G[sig.first][sig.second] != 'X') {
                //si la pos siguiente es una 't', acabamos
                if (G[sig.first][sig.second] == 't') return d+1;
                //sino, añadimos la pos que estamos mirando y la marcamos con una 'X' (ya no nos interesa)
                else {
                    Q.push({sig, d+1});
                    G[sig.first][sig.second] = 'X';
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m, r, c;
    cin >> n >> m;
    Grafo G(n, vector<char>(m));
    read_graph(G, n, m);
    cin >> r >> c;
    int p = DFS(G, r, c);
    if (p == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << p << endl;
}