#include <iostream>
using namespace std;

int main() {
    int c = 0;
    int n;
    cin >> n;
    char c1,c2,s;
    cin >> c1 >> c2;

    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (s >= c1 and s <= c2) ++c;
    }
    cout << c << endl;
}