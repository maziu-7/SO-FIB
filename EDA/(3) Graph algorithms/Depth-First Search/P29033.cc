#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Grafo;

bool colorear(const Grafo& G, int u, int col, vector<int>& color) {
    if (color[u] == -1) { //no está pintado
        color[u] = col;
        for (int v : G[u]) {
            if (not colorear(G, v, 1-col, color)) return false;
        }
        return true;
    }
    return color[u] == col;
}

bool dos_colors(const Grafo& G) {
    int n = G.size();
    vector<int> vis(n, -1);

    for (int i = 0; i < n; ++i) {
        if (vis[i] == -1) {
            if (not colorear(G, i, 1, vis)) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Grafo G(n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        if (dos_colors(G)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}