#include <iostream>
using namespace std;

int main() {
    int a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;

    if (a1 == a2 and b1 == b2) cout << "= , ";
    else if (a1 >= a2 and b2 >= b1) cout << "1 , ";
    else if (a2 >= a1 and b1 >= b2) cout << "2 , ";
    else cout << "? , ";

    int start;
    if (a1 > a2) start = a1;
    else start = a2;

    int end;
    if (b1 < b2) end = b1;
    else end = b2;

    if (start <= end) cout << '[' << start << ',' << end << ']' << endl;
    else cout << "[]" << endl;
}