#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (b+c == 2*a or a+c == 2*b or a+b == 2*c) cout << "YES" << endl;
    else cout << "NO" << endl;
}