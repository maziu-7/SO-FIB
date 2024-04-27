#include <iostream>
using namespace std;

int main() {
    int n,x;
    cin >> x;
    int c = 0;
    
    while (cin >> n) {
        if (n%x == 0) ++c;
    }
    cout << c << endl;
}