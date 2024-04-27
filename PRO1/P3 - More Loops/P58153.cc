#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    
    int n,m;
    
    while (cin >> n >> m) {
        double sum = 0;
        
        for (int i = m+1; i <= n; ++i) sum += 1/double(i);
        
        cout << sum << endl;
    }
}