#include <iostream>
#include <string>
using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j) {
    // Cas base: Quan i >= j, no cal fer res, ja que ja hem revertit tot el substring
    if (i >= j) {
        return;
    }

    // Intercanviem els carÃ cters a les posicions i i j
    swap(s[i], s[j]);

    // Continuem revertint el substring restant (i+1..j-1)
    reverseSubstring(s, i + 1, j - 1);
}