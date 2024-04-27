#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(1);

    int n;
    double deg;
    cin >> n;
    char temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp >> deg;
        if (temp == 'F') cout << "C " << (deg-32)/1.8 << endl;
        else cout << "F " << (1.8*deg)+32 << endl;
    }
}