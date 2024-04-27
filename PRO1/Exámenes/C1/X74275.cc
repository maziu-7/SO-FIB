#include <iostream>
using namespace std;

int main() {
    int n,m;
    int c = 1;

    cin >> n;
    bool found = false;
    while (not found and cin >> m and m != -1) {
        if ((n+m)%10 == 0) found = true;
        else ++c;
    }
    if (found) cout << m << ": " << c << endl;
    else cout << "No existe" << endl;
}