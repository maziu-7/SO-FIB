#include <iostream>
using namespace std;

bool is_increasing(int n) {
    if (n < 10) return true;
    if (n%10 >= (n/10)%10) return is_increasing(n/10);
    return false;
}