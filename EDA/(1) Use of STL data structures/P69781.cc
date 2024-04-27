#include <unordered_map>
#include <iostream>
using namespace std;

#define MAX 100000000

int main() {
    int x,y,n;
    unordered_map<int,int> m;
    while (cin >> x >> y >> n) {
        bool repeated = false;
        int c = 0;
        while (not repeated and n <= MAX) {
            if (m.find(n) != m.end()) {
                c = c - m[n];
                repeated = true;
            }
            ++c;
            m[n] = c;
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;
        }
        m.clear();
        if (repeated) cout << c << endl;
        else cout << n << endl;
    }
}