#include "treeOfSizes.hh"

BinTree<int> treeOfSizes(BinTree<int> t) {
    if (t.empty()) return BinTree<int>();
    BinTree<int> left, right;
    int nodes = 1;
    if (!t.left().empty()) {
        left = treeOfSizes(t.left());
        nodes += left.value();
    }
    if (!t.right().empty()) {
        right = treeOfSizes(t.right());
        nodes += right.value();
    }
    return BinTree<int>(nodes, left, right);
}