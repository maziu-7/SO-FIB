#include <iostream>
using namespace std;

int main() {
    int n,b;

    while (cin >> n >> b) {
        int p = 1;
        int c = 0;
        while (p <= b) {
            ++c;
            p = 1;
            for (int i = 0; i < n; ++i) p *= c;
        }
        if (c == 0) cout << c << endl;
        else cout << c-1 << endl;
    }
}