#include <iostream>
using namespace std;

int main() {
    int n,b;
    cin >> b;
    while (cin >> n) {
        int sum = 0;
        int x = n;
        while (x > 0) {
            sum += x%b;
            x /= b;
        }
        cout << n << ": " << sum << endl;
    }
}