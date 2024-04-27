#include <iostream>
using namespace std;

void reverse_half(int& n, int& c) {
    string word;
    if (cin >> word) {
        ++n;
        reverse_half(n, c);
        if (n/2 < c) {
            cout << word << endl;
        }
        ++c;
    }
}

int main() {
    int n = 1;
    int c = 1;
    reverse_half(n, c);
}