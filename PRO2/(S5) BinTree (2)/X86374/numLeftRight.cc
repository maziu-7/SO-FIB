#include "numLeftRight.hh"

BinTree<int> canvi(BinTree<int> t, int esq, int dreta) {
    BinTree<int> a_esquerra, a_dreta;
    if (!t.left().empty()) a_esquerra = canvi(t.left(), esq+1, dreta);
    if (!t.right().empty()) a_dreta = canvi(t.right(), esq, dreta+1);
    if (t.value() == -1) return BinTree<int> (esq, a_esquerra, a_dreta);
    else return BinTree<int> (dreta, a_esquerra, a_dreta);
}

BinTree<int> numLeftRight(BinTree<int> t) {
    BinTree<int> canviat;
    if (!t.empty()) canviat = canvi(t, 0, 0);
    return canviat;
}