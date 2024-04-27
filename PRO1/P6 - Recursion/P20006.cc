#include <iostream>
using namespace std;

int op() {
    char c;
    cin >> c;
    if (c >= '0' and c <= '9') return c - '0';
    else {
        int a = op();
        int b = op();
        if (c == '+') return a + b;
        else if (c == '-') return a - b;
        return a*b;
    }
}

int main() {
    cout << op() << endl;
}