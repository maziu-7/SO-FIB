#include <iostream>
#include "BinTree.hh"
using namespace std;

bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false;
    else if (a.value() == x) {
        a = BinTree<int>();
        return true;
    }
    else {
        BinTree<int> izq = a.left();
        BinTree<int> der = a.right();
        bool found = poda_subarbre(izq,x);
        if (not found) found = poda_subarbre(der,x);
        a = BinTree<int>(a.value(),izq,der);
        return found;
    }
}