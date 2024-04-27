#include "evaluate.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna l'avaluació de l'expressió representada per t.
bool evaluate(BinTree<string> t) {
    if (t.left().empty() and t.right().empty()) {
        if (t.value() == "true") return true;
        return false;
    }
    else {
        if (t.value() == "and") return evaluate(t.left()) and evaluate(t.right());
        else if (t.value() == "or") return evaluate(t.left()) or evaluate(t.right());
        else return (not evaluate(t.left()));
    }
}