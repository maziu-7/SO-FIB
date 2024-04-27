#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;
    while (n != -1) {
        int n_digits = 1;
        int sum = 0;
        while (n > 0) {
            if ((n%10)%2 != 0) {
                sum += n%10 * n_digits;
                n_digits *= 10;
            }
            n /= 10;
        }
        cout << sum << endl;
        cin >> n;
    }
}