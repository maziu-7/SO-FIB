#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;

    cout << "The number of digits of " << n << " is ";
    if (n == 0) cout << 1 << "." << endl;
    else {
        while (n > 0) {
        n /= 10;
        ++c;
        }
        cout << c << "." << endl;
    }   
}