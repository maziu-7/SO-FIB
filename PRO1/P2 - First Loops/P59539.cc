#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    double sum = 0;
    cin >> n;

    for (double i = 1; i <= n; ++i) sum += 1/i;
    cout << sum << endl;
}