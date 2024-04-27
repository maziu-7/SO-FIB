#include <iostream>
using namespace std;

void decompose(int n, int& h, int& m, int& s) {
    h = n/3600;
    m = (n/60)%60;
    s = n%60;
}