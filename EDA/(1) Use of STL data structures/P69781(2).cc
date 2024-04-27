#include <unordered_map>
#include <iostream>
using namespace std;

#define MAX 100000000

int main() {
    int x,y,n;
    while (cin >> x >> y >> n) {
        unordered_map<int,int> m;
        bool repeated = false;
        int c = 0;
        m.insert({n, c});
        auto it = m.begin();

        while (not repeated and n <= MAX) {
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            ++c;
            it = m.find(n);
            if (it == m.end()) m.insert({n, c}); //m[n] = c;
            else repeated = true;
        }
        if (repeated) cout << c - it->second << endl;
        else cout << n << endl;
    }
}