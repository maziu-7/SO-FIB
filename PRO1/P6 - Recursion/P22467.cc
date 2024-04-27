#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int sqrt = 2; sqrt*sqrt <= n; ++sqrt) {
        if (n%sqrt == 0) return false;
    }
    return true;
}

int sum_digits(int n) {
    if (n < 10) return n;
    return n%10 + sum_digits(n/10);
}

bool is_perfect_prime(int n) {
    if (n < 10) return is_prime(n);
    return is_prime(n) and is_perfect_prime(sum_digits(n));
}