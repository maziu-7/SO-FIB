#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    
    double n;
    double c = 0;
    double t = 0;
    
    while (cin >> n) {
        t += n;
        ++c;
    }
    cout << t/c << endl;
}