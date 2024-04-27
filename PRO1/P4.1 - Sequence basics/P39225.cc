#include <iostream>
using namespace std;

int main() {
    int n,x;
    int i = 0;
    cin >> n;
    
    cout << "At the position " << n << " there is a(n) ";
    while (x != -1 and cin >> x) {
        ++i;
        if (i == n) cout << x << "." << endl;
    }
}