#include "removeAll.hh"

BT removeAll(const string &extension, const BT &t) {
    BT left, right;
    if (!t.empty()) {
    if (t.right().empty() && t.left().empty()) {
        if (t.value().substr(t.value().size()-extension.size()) == extension) return BT();
    }
    else {
        if (!t.left().empty()) left = removeAll(extension, t.left());
        if (!t.right().empty()) right = removeAll(extension, t.right());
    }
    }
    return BT(t.value(), left, right);
}