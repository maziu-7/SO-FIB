#include <iostream>
using namespace std;

void drawRhombus(int n, int spaces) {
    if (n == 1) {
        for (int i = 0; i < spaces - n; ++i) cout << ' ';
        for (int i = 0; i < 2*n - 1; ++i) cout << '*';
        cout << endl;
    }

    else {
        drawRhombus(n - 1, spaces);
        int x = 2;
        //aux is a variable needed to modify the values of x
        //in each iteration of the loop, so we can print the
        //spaces and stars needed in each row
        int aux = 1;
        for (int i = 0; i < n*2 - 3; ++i) {
            // Print leading spaces
            for (int j = 0; j < spaces - x; ++j) {
                cout << ' ';
            }
            // Print stars
            for (int j = 0; j < 2*x - 1; ++j) {
                cout << '*';
            }
            // Move to the next row
            cout << endl;
            if (aux == 1 and x == n) aux = -1;
            else if (aux == -1 and x == 2) aux = 1;
            x += aux;
        }
        drawRhombus(n - 1, spaces);
    }
}

int main() {
    int n;
    while (cin >> n) {
        drawRhombus(n, n);
        cout << endl;
    }
}