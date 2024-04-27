#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int secuencia(const set<int>& S) {
    if (S.empty()) return 0;

    int c = 1;
    auto it = S.begin();
    auto seg = S.begin();
    ++seg;

    while (seg != S.end()) {
        if ((*it)%2 != (*seg)%2) ++c;
        ++it;
        ++seg;
    }
    return c;
}

int main() {
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        
        set<int> S;
        int n;
        while (iss >> n) S.insert(n);
        
        cout << secuencia(S) << endl;
    }
}