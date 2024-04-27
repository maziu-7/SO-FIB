#include <iostream>
using namespace std;

int reverse(int n) {
    int r = 0;
    
    while (n > 0) {
        r *= 10;
        r += n%10;
        n /= 10;
    }
    return r;
}

bool is_palindromic(int n) {
    return (reverse(n) == n);
}