#include <iostream>
using namespace std;

void base(int num, int notation) {
    int temp = num/notation;
    if (temp != 0) base(temp, notation);
    if (num%notation < 10) cout << num%notation;
    else cout << char('A' + num%notation - 10);
}

int main() {
    int num;
    while (cin >> num) {
        cout << num << " = ";
        base(num,2);
        cout << ", ";
        base(num,8);
        cout << ", ";
        base(num,16);
        cout << endl;
    }
}