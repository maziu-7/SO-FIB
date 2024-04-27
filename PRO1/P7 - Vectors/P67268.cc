#include <iostream>
#include <vector>
using namespace std;

void reverse(const vector<int>& v) {
    int last = v.size() - 1;
    while (0 < last) {
        cout << v[last] << ' ';
        --last;
    }
    cout << v[0];
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        if (n != 0) reverse(v);
        cout << endl;
    }
}