#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

bool hay_ciclo(const Graf& G, int u, int ant, vector<bool>& vis) {
    if (vis[u]) return true;
    else {
        vis[u] = true;
        for (int v : G[u]) {
            if (v != ant and hay_ciclo(G, v, u, vis)) return true;
        }
        return false;
    }
}

int bosque(const Graf& G) {
    int n = G.size();
    vector<bool> vis(n, false);
    int narb = 0;

    for (int i = 0; i < n; ++i) {
        if (not vis[i]) {
            if (hay_ciclo(G, i, -1, vis)) return -1;
            else ++narb;
        }
    }
    return narb;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graf G(n);
        //m aristas
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int narb = bosque(G);
        if (narb == -1) cout << "no" << endl;
        else cout << narb << endl;
    }
}