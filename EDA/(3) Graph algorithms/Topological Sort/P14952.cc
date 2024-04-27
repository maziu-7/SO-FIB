#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Grafo;

void topologica(const Grafo& G, vector<int>& ge, vector<int>& sol) {
    int n = G.size();
    priority_queue<int, vector<int>, greater<int>> PQ;
    //guardamos los que no tienen ninguna dependencia en PQ
    for (int i = 0; i < n; ++i) {
        if (ge[i] == 0) PQ.push(i);
    }

    while (not PQ.empty()) {
        int u = PQ.top();
        PQ.pop();
        sol.push_back(u);
        //adaycentes a u
        for (int v : G[u]) {
            if (--ge[v] == 0) PQ.push(v);
        }
    }
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Grafo G(n);
        vector<int> ge(n, 0);
        for (int i = 0; i < m; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            ++ge[y];
        }

        vector<int> sol;
        topologica(G, ge, sol);
        for (int i = 0; i < n; ++i) {
            if (i != 0) cout << ' ';
            cout << sol[i];
        }
        cout << endl;
    }
}