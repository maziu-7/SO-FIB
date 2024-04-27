#include <iostream>
using namespace std;

int main() {
    char s;
    int r,c;
    int sum = 0;
    int sum_odd = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> s;
            sum += s - '0';
            if (i%2 != 0) sum_odd += s - '0';
        }
    }
    cout << sum << " " << sum_odd << endl;
}