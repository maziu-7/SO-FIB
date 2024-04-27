#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n;
    
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /= 100;
    }
    if (sum%2 == 0) cout << " IS COOL" << endl;
    else cout << " IS NOT COOL" << endl;
}