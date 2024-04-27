#include <iostream>
using namespace std;

int main() {
    int n;
    int total = 0;

    cin >> n;
    while (n != -1) {
        int y = n%10;
        int aux = n;
        while (aux > 9) aux /= 10;
        if (y == aux) {
            ++total;
            cout << n << endl;
        }
        cin >> n;
    }
    cout << "total: " << total << endl;
}