#include <iostream>
#include "BinTree.hh"
using namespace std;

int sumOfTree(BinTree<int> t) {
    int sum = t.value();
    if (not t.right().empty()) sum += sumOfTree(t.right());
    if (not t.left().empty()) sum += sumOfTree(t.left());
    return sum;
}