#include <iostream>
using namespace std;

int main() { //m > 60, h > 24, 
    int h,m,d;
    cin >> h >> m >> d;
    m += d;
    while (m >= 60) {
        m -= 60;
        ++h;
        if (h == 24) h = 0;
        h %= 24;
    }
    cout << h/10 << h%10 << ":" << m/10 << m%10 << endl;
}