#include <iostream>
#include <cmath>
using namespace std;

double convert(double& x) {
    return x = x*(M_PI/180);
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    
    double n;
    while (cin >> n) {
        convert(n);
        cout << sin(n) << " " << cos(n) << endl;
    }
}