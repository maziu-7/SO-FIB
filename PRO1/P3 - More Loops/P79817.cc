#include <iostream>
using namespace std;

int main() {
    int x,y;
    while (cin >> x >> y) {
        int pow = 1;
        for (int i = 0; i < y; ++i) {
            pow *= x;
        }
        cout << pow << endl;
    }
}