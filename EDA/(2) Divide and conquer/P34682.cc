#include <iostream>
#include <vector>
using namespace std;

int fixed_point(int a, const vector<int>& v, int i, int j) {
    if (i > j) return -1;
    int m = (i+j)/2;
    if (v[m] + a == m+1) {
        //condición original: m == i or (m > i and v[m-1] + a != m)
        if (m == i or v[m-1] + a != m) return m+1;
        else return fixed_point(a, v, i, m-1);
    }
    else if (v[m] + a > m+1) return fixed_point(a, v, i, m-1);
    else return fixed_point(a, v, m+1, j);
}

int main() {
    int n;
    int c = 1;
    while (cin >> n) {
        cout << "Sequence #" << c << endl;
        vector<int> S(n);
        for (int i = 0; i < n; ++i) cin >> S[i];
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            int f = fixed_point(a, S, 0, n-1);
            if (f == -1) cout << "no fixed point for " << a << endl;
            else cout << "fixed point for " << a << ": " << f << endl;
        }
        cout << endl;
        ++c;
    }
}