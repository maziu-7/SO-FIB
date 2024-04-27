#include <iostream>
using namespace std;

int main() {
    char c;
    bool low = false;
    
    while (c != '.' and cin >> c) {
        if (c == 'a') low = true;
    }
    if (low) cout << "yes" << endl;
    else cout << "no" << endl;
}