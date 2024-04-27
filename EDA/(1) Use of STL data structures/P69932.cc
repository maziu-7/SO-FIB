#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        set <int> S;
        int n;
        int c = 0;
        istringstream iss(s);
        while (iss >> n) S.insert(n);
        bool even = true;
        auto it = S.begin();
        while (it != S.end()) {
            if (it == S.begin()) {
                ++c;
                even = (*it%2 == 0);
            }
            else if (even and *it%2 != 0) {
                ++c;
                even = false;
            }
            else if (not even and *it%2 == 0) {
                ++c;
                even = true;
            }
            ++it;
        }
        cout << c << endl;
    }
}