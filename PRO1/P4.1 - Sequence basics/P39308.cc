#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        cout << "divisors of " << n << ":";

        int sqrt = 1;
        while (sqrt*sqrt < n) ++sqrt;

        for (int i = 1; i <= sqrt; ++i) {
            if (n%i == 0) cout << " " << i;
        }
        for (int i = sqrt - 1; i > 0; --i) {
            if (n%i == 0 and n/i != sqrt) cout << " " << n/i;
        }
        cout << endl;
    }
}