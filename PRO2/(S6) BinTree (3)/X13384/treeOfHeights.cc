#include "treeOfHeights.hh"

BinTree<int> i_treeOfHeights(BinTree<int> t, int &h) {
    if (t.empty()) {
        h = 0;
        return t;
    }
    else {
        int he,hd;
        BinTree<int> te = i_treeOfHeights(t.left(),he);
        BinTree<int> td = i_treeOfHeights(t.right(),hd);
        h = max(hd,he)+1;
        return BinTree<int>(h,te,td);
    }
}

BinTree<int> treeOfHeights(BinTree<int> t) {
    int h;
    return i_treeOfHeights(t,h);
}