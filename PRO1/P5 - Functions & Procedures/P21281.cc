#include<iostream>
using namespace std;

void factor(int n, int& f, int& q) {
    int i = 2;
    f = q = 0;
    
    while (i*i <= n) {
        int c = 0;
        
        while (n%i == 0) {
            n /= i;
            ++c;
            
            if (c > q) {
                q = c;
                f = i;
            }
        }
        ++i;
    }
    
    if (q == 0 and f == 0) {
        q = 1;
        f = n;
    }
}