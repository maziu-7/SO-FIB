#include <iostream>
#include <cmath>
using namespace std;

int power(int x) {
    return x*x;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    
    int n;
    while (cin >> n) {
        cout << power(n) << " " << sqrt(n) << endl;
    }
}