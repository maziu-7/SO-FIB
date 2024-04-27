#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    if (t.empty()) return BinTree<bool>();

    BinTree<bool> l = treeOfEvaluations(t.left());
    BinTree<bool> r = treeOfEvaluations(t.right());

    if (t.value() == "true") return BinTree<bool>(true,l,r);
    else if (t.value() == "false") return BinTree<bool>(false,l,r);

    if (t.value() == "and") return BinTree<bool>(l.value() and r.value(),l,r);
    else if (t.value() == "or") return BinTree<bool>(l.value() or r.value(),l,r);
    return BinTree<bool>(not l.value(),l,r);
}