#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < (n - 1) - i; ++j) cout << ' ';
            for (int k = 0; k < n + 2*i; ++k) cout << 'X';
            cout << endl;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n + 2*(n-1); ++j) cout << 'X';
            cout << endl;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < (n - 1) - i; ++j) cout << ' ';
            for (int k = 0; k < n + 2*i; ++k) cout << 'X';
            cout << endl;
        }
        cout << endl;
    }
}