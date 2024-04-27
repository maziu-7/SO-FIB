#include <iostream>
using namespace std;

int mcd(int a, int b) {
    while (b > 0) {
        int temp;
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void read_rational(int& num, int& den) {
    char x;
    cin >> num >> x >> den;
    
    int c = mcd(num,den);
    
    num /= c;
    den /= c;
}