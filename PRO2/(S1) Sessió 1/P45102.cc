#include <iostream>
using namespace std;

int op_par() {
    char c,p,s;
    cin >> c;
    if (c == '(') {
        int x = op_par();
        cin >> s;
        int y = op_par();
        cin >> p;
        if (s == '+') return x + y;
        else if (s == '-') return x - y;
        return x*y;
    }
    else return c - '0';
}

int main() {
    cout << op_par() << endl;
}