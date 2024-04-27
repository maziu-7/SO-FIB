#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt par;
    if (par.llegir()) {
        BinTree<ParInt> a_left, a_right;
        read_bintree_parint(a_left);
        read_bintree_parint(a_right);
        BinTree<ParInt> b(par, a_left, a_right);
        a = b;
    }
}

void write_bintree_parint(const BinTree<ParInt>& a);