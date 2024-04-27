#include <iostream>
using namespace std;

int main() {
    int n,x,y;
    int i = 0;
    cin >> n;
    
    bool found = false;
    while (not found and cin >> x) {
        ++i;
        found = i == n;
        y = x;
    }
    if (found) {
        cout << "At the position " << n;
        cout << " there is a(n) " << y << "." << endl;
    }
    else cout << "Incorrect position." << endl;
}