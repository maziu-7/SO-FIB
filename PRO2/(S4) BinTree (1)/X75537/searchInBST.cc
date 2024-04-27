#include <iostream>
#include "BinTree.hh"
using namespace std;

bool searchInBST(BinTree<int> t, int x) {
    if (t.value() > x) return (not t.left().empty() and searchInBST(t.left(),x));
    else if (t.value() < x) return (not t.right().empty() and searchInBST(t.right(),x));
    else return (t.value() == x);
}