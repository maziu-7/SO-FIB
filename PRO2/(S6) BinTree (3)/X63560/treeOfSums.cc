#include "treeOfSums.hh"

BinTree<int> treeOfSums(BinTree<int> t) {
    if (t.empty()) return BinTree<int>();
    BinTree<int> left, right;
    int suma = t.value();
    if (!t.left().empty()) {
        left = treeOfSums(t.left());
        suma += left.value();
    }
    if (!t.right().empty()) {
        right = treeOfSums(t.right());
        suma += right.value();
    }
    return BinTree<int>(suma, left, right);
}