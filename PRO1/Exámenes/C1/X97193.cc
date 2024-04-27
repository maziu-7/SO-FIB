#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    string s;
    double a,b,c;

    cin >> s;
    while (s != "acabar") {
        if (s == "area") {
            cin >> a >> b;
            cout << (a*b)/2 << endl;
        }
        else {
            cin >> a >> b >> c;
            cout << a+b+c << endl;
        }
        cin >> s;
    }
}