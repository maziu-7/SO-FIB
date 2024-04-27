#include <iostream>
using namespace std;

int main() {
    string p,s;
    cin >> p;
    int c = 1;
    bool found = false;

    while (not found and cin >> s) {
        if (p == s) found = true;
        else ++c;
    }
    if (found) cout << c << endl;
    else cout << "No existe" << endl;
}