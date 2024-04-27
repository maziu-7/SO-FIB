#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;
    while (n != 0) {
        int sum = 0;
        int i = 1;
        while (n > 0) {
            if ((n%10)%2 != 0) sum += n%10*i;
            else sum += (n+1)%10*i;
            i *= 10;
            n /= 10;
        }
        cout << sum << endl;
        cin >> n;
    }
}