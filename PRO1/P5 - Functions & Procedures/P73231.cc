#include <iostream>
using namespace std;

int max2 (int x, int y) {
    if (x > y) return x;
    return y;
}

int max4(int a, int b, int c, int d) {
    return max(max2(a,b),max2(c,d));
}