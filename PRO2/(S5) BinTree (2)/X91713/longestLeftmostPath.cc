#include "longestLeftmostPath.hh"
// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
// seguint el camí més llarg. En cas de varis camins màxims,
// escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinTree<int> t) {
    if (t.empty()) return list<int>();
    list<int> leftPath = longestLeftmostPath(t.left());
    list<int> rightPath = longestLeftmostPath(t.right());
    if (leftPath.size() < rightPath.size()) {
        rightPath.push_front(t.value());
        return rightPath;
    }
    else {
        leftPath.push_front(t.value());
        return leftPath;
    }
}