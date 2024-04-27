#include <iostream>
using namespace std;

int main() {
    int n;
    int i = 1;
    bool found = false;
    
    while (not found and cin >> n) {
        if (n%2 == 0) {
            found = true;
        }
        else ++i;
    }
    cout << i << endl;
}