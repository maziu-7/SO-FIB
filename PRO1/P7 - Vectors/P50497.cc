#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const string& s) {
    bool aux = true;
    int i = 0;
    int j = s.size() - 1;
    while (aux and i < j) {
        aux = s[i] == s[j];
        ++i;
        --j;
    }
    return aux;
}