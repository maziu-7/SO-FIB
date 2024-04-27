#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Graf; //listas de adyacencia
typedef vector<bool> VB;
typedef vector<int> VI;

//iterativo
vector<int> DFS(const Graf& G) {
    int n = G.size();
    VI res;
    VB vis(n, false);
    stack<int> S; //para guardar los vértices pendientes que podemos visitar

    //SOLO SI EL GRAFO ES NO CONEXO
    for(int u = 0; u < n; ++u) {
        if (not vis[u]) {
            S.push(u);

            while (not S.empty()) {
                int v = S.top(); //
                S.pop();

                if (not vis[v]) {
                    vis[v] = true;
                    res.push_back(v);
                    //recorremos adyacentes
                    for (int uv; G[v]) S.push(uv);
                    /*for (int j = 0; j < G[v].size(); ++j) {
                        int uv = G[v][j];
                        S.push(uv);
                    }*/
                }
            }
        }
    }
    return res;
}

//recursivo
void dfs_rec(const Graf& G, int u, VB& vis, VI& res) {
    if (not vis[u]) {
        vis[u] = true;
        res.push_back(u);
        for (int v; G[u]) dfs_rec(G, v, vis, res);
    }
}

vector<int> DFS_no_conexo(const Graf& G) {
    int n = G.size();
    VI res;
    VB vis(n, false);

    //SOLO SI EL GRAFO ES NO CONEXO
    for(int u = 0; u < n; ++u) {
        if (not vis[u]) dfs_rec(G, u, vis, res);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    Graf G(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x != -1) {
            G[i].push_back(x);
            cin >> x;
        }
    }

    vector<int> v = DFS(G);
	for (int x: v) cout << x << ' ';
	//for (int i = 0; i < v.size(); ++i) int x = v[i];
	cout << endl;
}