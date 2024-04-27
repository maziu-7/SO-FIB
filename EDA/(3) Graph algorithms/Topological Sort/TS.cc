#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Grafo;

void topologica(const Grafo& G, vector<int>& sol) {
    int n = G.size();
    vector<int> ge(n, 0);
    //recorremos el grafo para calcular las dependencias de cada vértice
    for (int i = 0; i < n; ++i) {
        for (int v : G[i]) { //for (int j = 0; j < G[i].size(); ++j) int v = G[i][j];
            ++ge[v];
        }
    }
    //guardamos los que no tienen ninguna dependencia en una pila (p.ej)
    stack<int> S;
    for (int i = 0; i < n; ++i) {
        if (ge[i] == 0) S.push(i);
    }

    //recorremos el resto
    while (not S.empty()) {
        int u = S.top();
        S.pop();
        //la tarea u ya se puede realizar porque está en la pila
        sol.push_back(u);
        //adyacentes de u
        for (int v : G[u]) {
            --ge[v];
            if (ge[v] == 0) S.push(v);
        }
    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Grafo G(n);
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
        }

        vector<int> sol;
        topologica(G, sol);
        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << ' ';
            cout << sol[i];
        }
        cout << endl;
    }
}