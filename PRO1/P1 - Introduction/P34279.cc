#include <iostream>
using namespace std;

int main() {
    int h,m,s;
    cin >> h >> m >> s;

    ++s;
    if (s == 60) {
        ++m;
        s = 0;
        if (m == 60) {
            ++h;
            m = 0;
            if (h == 24) h = 0;
        }
    }
    cout << h/10 << h%10 << ":" << m/10 << m%10 << ":" << s/10 << s%10 << endl;
}