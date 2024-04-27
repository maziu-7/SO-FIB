#include <iostream>
using namespace std;

int main() {
    char c;
    int i = 0;
    
    while (c != '.' and cin >> c) {
        if (c == 'a') ++i;
    }
    cout << i << endl;
}