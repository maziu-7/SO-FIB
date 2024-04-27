#include <iostream>
using namespace std;

void reverse(int& n) {
    string word;
    if (cin >> word and n > 0) {
        reverse(n);
        if (n != 0) {
            cout << word << endl;
            --n;
        }
    }
}

int main() {
    int n;
    cin >> n;
    reverse(n);
}