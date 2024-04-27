#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int counter = 0;
        while (n > 100) {
            int div = (n/10)%10;
            if (div > n%10 and div > (n/100)%10) ++counter;
            n /= 10;
        }
        cout << counter << endl;
    }
}