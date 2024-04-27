#include <iostream>
using namespace std;

int main() {
    int d,n,t;
    cin >> d >> n >> t;
    
    int c = 0;
    
    for (int i = 0; i < t; ++i) {
        int w;
        cin >> w;
        n -= d;
        n += w;
        if (n > 0) ++c;
    }
    cout << c << endl;
}