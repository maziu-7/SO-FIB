#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int max;
        cin >> max;
        for (int i = 1; i < n; ++i) {
            int m;
            cin >> m;
            if (m > max) max = m;
        }
        cout << max << endl;
    }
}