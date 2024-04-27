#include <iostream>
using namespace std;

int main() {
    char c;
    int x = 0;
    
    while (cin >> c and c != '.') {
        if (c == 'a') ++x;
    }
    cout << x << endl;
}