#include<iostream>
using namespace std;

bool is_perfect(int n) {
    int div = 1;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) div += n/i + i;
    }
    return (div == n and n != 0 and n != 1);
}