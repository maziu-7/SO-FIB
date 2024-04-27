#include <iostream>
using namespace std;

int simpleAlternatedSum(int n) {
    // Cas base: si n és 1, retornem 1
    if (n == 1) {
        return 1;
    }
    // Cas recursiu: si n és parell, restem n; si n és senar, sumem n
    if (n % 2 == 0) return -n + simpleAlternatedSum(n - 1);
    return n + simpleAlternatedSum(n - 1);
}