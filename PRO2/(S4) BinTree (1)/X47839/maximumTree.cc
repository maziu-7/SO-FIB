#include <iostream>
#include "BinTree.hh"
using namespace std;

BinTree<int> maximumTree(BinTree<int> t1,BinTree<int> t2) {
    if (t1.empty() and t2.empty()) return BinTree<int>();
    else if (t1.empty()) return t2;
    else if (t2.empty()) return t1;
    else {
        int x;
        if (t1.value() >= t2.value()) x = t1.value();
        else x = t2.value();
        BinTree<int> r1 = maximumTree(t1.left(),t2.left());
        BinTree<int> r2 = maximumTree(t1.right(),t2.right());
        return BinTree<int>(x,r1,r2);
    }
}