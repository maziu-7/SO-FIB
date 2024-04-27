#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

typedef vector<int> vi;
typedef vector<vi> vvi;


int main () {
    int n, m;
    while (cin >> n >> m) {
        vvc table (n, vc(m));
        vvi dp (n, vi(m, 1)); // we do a dp counting the maximal size constant square with right down vertice being (i,j);

        int sol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> table[i][j];
                if (j > 0 and i > 0) {
                    if (table[i][j] == table[i-1][j] and table[i][j] == table[i][j-1] and table[i][j] == table[i-1][j-1]) {
                        dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j], dp[i-1][j-1]));
                    }
                }
                sol += dp[i][j];
            }
        }
        cout << sol << endl;
    }
}