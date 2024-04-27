#include <iostream>
using namespace std;

int main() {
    int d,n;
    bool d_even = false;
    cin >> d;

    while (not d_even and cin >> n) {
        int new_n = n;
        int num_even = 0;
        while (new_n > 0) {
            if (new_n%10 == d) ++num_even;
            new_n /= 10;
        }
        if (num_even%2 == 0) d_even = true;
    }
    if (d_even) cout << n << endl;
    else cout << "no d-par" << endl;
}