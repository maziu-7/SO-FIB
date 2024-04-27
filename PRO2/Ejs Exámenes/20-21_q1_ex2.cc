#include "BinTree.hh"

/*
Pre: a conté només zeros i uns
Post: el resultat ens diu si a és un arbre 0-1
*/

bool arbre01(const BinTree<int>& a) {
    if (a.empty()) return true;
    else {
        if (not a.left().empty() and a.left().value() == a.value()) return false;
        if (not a.right().empty() and a.right().value() == a.value()) return false;
        //HI1: el resultat indica si el subarbre esquerre d'a és un arbre 0-1  
        //HI2: el resultat indica si el subarbre dret d'a és un arbre 0-1  
        return arbre01(a.right()) and arbre01(a.left());
    }
}