#include <iostream>
using namespace std;

int main() {
    int n,m;
    
    bool end = false;
    while (cin >> n >> m) {
        if (end) cout << endl;
        int c = 9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << c%10;
                --c;
                if (c == -1) c = 9;
            }
            cout << endl;
        }
        end = true;
    }
}