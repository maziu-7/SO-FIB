#include <iostream>
using namespace std;

void print(int d) {
    if (d == 0) cout << d;
    else {
        cout << d;
        for (int i = 0; i < d; ++i) {
            print(d - 1);
            cout << d;
        }
    }
}

int main() {
    int d;
    while (cin >> d) {
        print(d);
        cout << endl;
    }
}