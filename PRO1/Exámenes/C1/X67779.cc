#include <iostream>
using namespace std;

int main() {
    int n;
    int max = -1;
    int pos = 0;

    bool found = false;
    while (not found and cin >> n) {
        if (n > max) {
            max = n;
            pos = 0;
        }
        else if (n*2 == max and pos%2 == 0) found = true;
        else ++pos;
    }
    if (found) cout << n << endl;
    else cout << "no existe" << endl;
}