#include <iostream>
using namespace std;

int main() {
    int h0,m0,h1,m1;
    cin >> h0 >> m0 >> h1 >> m1;
    
    if (m0 > m1) {
        --h1;
        m1 += 60;
    }
    if (h0 > h1) h1 += 24;
    h1 -= h0;
    m1 -= m0;
    cout << h1/10 << h1%10 << ':' << m1/10 << m1%10 << endl;
}