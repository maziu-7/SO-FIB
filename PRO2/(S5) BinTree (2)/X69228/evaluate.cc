#include "evaluate.hh"

void reverse(const string& a, int it, string& result) {
    if (it < 0) return;
    result += a[it];
    reverse(a, it - 1, result);
}

string evaluate(BinTree<string> t) {
    if (t.value() == "Reverse") {
        string left, reversed = "";
        if (!t.left().empty()) left = evaluate(t.left());
        reverse(left, left.size()-1, reversed);
        return reversed;
    }
    else if (t.value() == "Concat") {
        string left, right;
        if (!t.left().empty()) left = evaluate(t.left());
        if (!t.right().empty()) right = evaluate(t.right());
        return left + right;
    }
    else return (t.value());
}