#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i]; //leemos el vector

    string s;
    while (cin >> s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            //dependiendo de cada char del string, actualizamos sum
            if (s[i] == '+') sum += v[i];
            else sum -= v[i];
        }
        cout << sum << endl;
    }
}