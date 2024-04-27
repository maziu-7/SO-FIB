#include <iostream>
using namespace std;

int main() {
    int n,x;
    cin >> n;
    cout << "nombres que acaben igual que " << n << ":" << endl;
    int i = 0;
    
    while (cin >> x) {
        if (n%1000 == x%1000) {
            cout << x << endl;
            ++i;
        }
    }
    cout << "total: " << i << endl;
}