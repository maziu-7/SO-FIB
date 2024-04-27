#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) cout << ' ';
        cout << 'V';
        if (i + 1 < n) {
            for (int j = 0; j < 2*n - 3 - i*2; ++j) cout << ' ';
            cout << 'V';
        }
        cout << endl;
    }
}