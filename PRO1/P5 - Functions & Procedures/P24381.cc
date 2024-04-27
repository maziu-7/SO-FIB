#include <iostream>
using namespace std;

void not_middle(int n, char c) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << " ";

        cout << c << endl;
    }
}

void cross(int n, char c) {
        not_middle((n-1)/2, c);

        for (int i = 0; i < n; ++i)
            cout << c;

        cout << endl;

        not_middle((n-1)/2, c);
}

int main() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    cross(n,c);
}