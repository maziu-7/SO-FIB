#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Arc; //first = distancia, segundo = vértice
typedef vector<vector<Arc>> Grafo;
const int inf = 1e9; //INT_MAX

int dijkstra(const Grafo& G, int ini, int fin) {
    int n = G.size();
    vector<int> dist(n, inf);
    vector<bool> vis(n , false);
    priority_queue<Arc, vector<Arc>, greater<Arc>> PQ;

    PQ.push({0, ini});
    dist[ini] = 0;

    while (not PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();
        if (u == fin) return dist[u];
        if (not vis[u]) {
            vis[u] = true;
            //adyacentes a u
            for (Arc uv : G[u]) {
                int v = uv.second;
                int c = uv.first;
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    PQ.push({dist[v], v});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Grafo G(n);
        for (int i = 0; i < m; ++i) {
            int x,y,c;
            cin >> x >> y >> c;
            G[x].push_back({c,y});
        }
        int ini, fin;
        cin >> ini >> fin;
        int dist = dijkstra(G, ini, fin);

        if (dist == -1) cout << "no path from " << ini << " to " << fin << endl;
        else cout << dist << endl;
    }
}