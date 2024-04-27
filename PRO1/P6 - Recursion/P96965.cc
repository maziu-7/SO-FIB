#include <iostream>
using namespace std;

int sum_of_digits(int x) {
    if (x < 10) return x;
    return sum_of_digits(x/10) + x%10;
}

int reduction_of_digits(int x) {
    if (x < 10) return x;
    return reduction_of_digits(sum_of_digits(x));
}