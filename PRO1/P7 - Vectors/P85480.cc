#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

bool get_sum(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int k = i + 1; k < v.size(); ++k) {
            if (prime(v[i] + v[k])) return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        if (get_sum(v)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}