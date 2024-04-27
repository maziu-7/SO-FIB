#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;
typedef vector<int> Row2;
typedef vector<Row2> Matrix2;

void read(Matrix& u, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> u[i][j];
    }
}

int main() {
    int n,m;
    while (cin >> n >> m)  {
        vector<int> count(10,0);
        Matrix u(n, vector<char> (m));
        Matrix2 v(n, vector<int> (m));
        read(u, n, m);
        vector<int> n1(10);
        vector<int> n2(10);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) ++n1[u[i][j] - '0'];
            for (int k = 0; k < m; ++k) v[i][k] += n1[u[i][k] - '0'];
            n1 = count;
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) ++n2[u[i][j] - '0'];
            for (int k = 0; k < n; ++k) v[k][j] += n2[u[k][j] - '0'];
            n2 = count;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << v[i][j]%10;
            cout << endl;
        }
        cout << endl;
    }
}