#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    
    double n;
    cin >> n;

    double s1 = 0;
    double s2 = 0;

    for (double i = 1; i <= n; ++i) {
        double v;
        cin >> v;
        s1 += v*v;
        s2 += v;
    }
    cout << (1/(n-1))*s1 - (1/(n*(n-1)))*s2*s2 << endl;
}