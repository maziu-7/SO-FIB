#include <iostream>
#include <vector>
using namespace std;

void reverse(string s) {
    int size = s.size() - 1;
    for (int i = size; i >= 0; --i) cout << s[i];
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = n - 1; i >= 0; --i) {
        reverse (s[i]);
        cout << endl;
    }
}