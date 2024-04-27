#include <iostream>
using namespace std;

int fatten(int x) {
    if (x < 10) return x;
    int f = fatten(x/10);
    int maximum = max(x%10, f%10);
    return f*10 + maximum;
}