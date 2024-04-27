#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> fila;
typedef vector<fila> pla;
typedef vector<pla> cub;

void existeix(cub& c, int n, int i, int j, int k, int ini_i, int ini_j, int ini_k, fila& ratlles) {
	int original = c[i][j][k];

	int count = 1;
	i += ini_i;
	j += ini_j;
	k += ini_k;
	while (not (i < 0 or i >= n or j < 0 or j >= n or k < 0 or k >= n) and c[i][j][k] == original) {
		i += ini_i;
		j += ini_j;
		k += ini_k;
		++count;
		++ratlles[count];
	}

}


int main() {
	int n;
	bool first = true;
	while (cin >> n) {

		cub c(n, pla(n, fila (n)));
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cin >> c[i][j][k];
				}
			}
		}

		fila ratlles(n + 1, 0);
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					//cerr << i << " -----  " << j << " -----  " << k << endl;
					bool wip = true;
					int ini_i = -1;
					while (ini_i <= 1 and wip) {
						int ini_j = -1;
						while (ini_j <= 1 and wip) {
							int ini_k = -1;
							while (ini_k <= 1 and wip) {
								//cerr << ini_i << " -----  " << ini_j << " -----  " << ini_k << endl;			
								existeix(c, n, i, j, k, ini_i, ini_j, ini_k, ratlles);
								++ini_k;
								if (ini_k == 0 and ini_j == 0 and ini_i == 0) wip = false;
							}
							++ini_j;
						}
						++ini_i;
					}

				}
			}
		}
		if (not first) {
			cout << endl;
		}
		first = false;
		for (int i = 2; i <= n; i++) {
			cout << "Ratlles de mida " << i << ": " << ratlles[i] << endl;
		}
	}
}