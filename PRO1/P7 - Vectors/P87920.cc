#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        bool equal = false;
        int c = 0;

        while (c < n and not equal) {
            if (sum - v[c] == v[c]) {
                cout << "YES" << endl;
                equal = true;
            }
            ++c;
        }
        if (not equal) cout << "NO" << endl;
    }
}