#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    double c;
    double i;
    int t;
    cin >> c >> i >> t;
    
    string s;
    cin >> s;
    
    if (s == "simple") cout << c + (c*t*i)/100 << endl;
    else {
        for (int j = 0; j < t; ++j) {
            c += (c*i)/100;
        }
        cout << c << endl;
    }
}