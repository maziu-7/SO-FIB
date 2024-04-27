#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf; //listas de adyacencia

vector<int> BFS(const Graf& G) {
	int n = G.size();
	vector<int> res;
	vector<int> vis(n, false);
	queue<int> Q;
	
	//no conexo
	for (int i = 0; i < n; ++i) {
		if (not vis[i]) {
			Q.push(i);
			vis[i] = true;
			
			while (not Q.empty()) {
				int u = Q.front();
				Q.pop();
				
				res.push_back(u);
				//adyacentes
				for (int v: G[u]) {
					if (not vis[v]) {
						vis[v] = true;
						Q.push(v);
					}
				}
			}
		}
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
	
	vector<int> v = BFS(G);
	for (int x: v) cout << x << ' ';
	cout << endl;
}