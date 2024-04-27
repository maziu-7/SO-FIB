#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"

void sumak(BinTree<ParInt>& a, int k) {
    if (not a.empty()) {
        ParInt p(a.value().primer(), a.value().segon() + k);
        BinTree<ParInt> l = a.left();
        BinTree<ParInt> r = a.right();
        sumak(l,k);
        sumak(r,k);
        a = BinTree<ParInt>(p,l,r);
    }
}