#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        
        string s;
        cin >> s;
        
        if (s == "rectangle") {
            double l,w;
            cin >> l >> w;
            cout << l*w << endl;
        }
        
        else {
            double r;
            cin >> r;
            cout << M_PI*r*r << endl;
        }
    }
}