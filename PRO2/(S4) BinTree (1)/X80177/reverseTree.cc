#include <iostream>
#include "BinTree.hh"
using namespace std;

BinTree<int> reverseTree(BinTree<int> t) {
    if (t.empty()) return t;
    else {
        BinTree<int> ti = reverseTree(t.left());
        BinTree<int> td = reverseTree(t.right());
        return BinTree<int> (t.value(),td,ti);
    }
}