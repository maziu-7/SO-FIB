#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cout << "*";
    cout << endl;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < i; ++j) cout << ' ';
        cout << '*';
        for (int j = 0; j < n - 2 - i; ++j) cout << ' ';
        cout << '*' << endl;
    }
    for (int i = 0; i < n - 1; ++i) cout << ' ';
    cout << '*' << endl;
}