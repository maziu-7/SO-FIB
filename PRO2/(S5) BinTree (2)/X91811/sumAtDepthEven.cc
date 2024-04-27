#include "sumAtDepthEven.hh"

int suma_parells(BinTree<int> t, int nivell) {
    int suma = 0;
    if (!t.left().empty()) suma += suma_parells(t.left(), nivell+1);
    if (!t.right().empty()) suma += suma_parells(t.right(), nivell+1);
    if (nivell%2 == 0) suma += t.value();
    return suma;
}
// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinTree<int> t) {
    if (!t.empty()) {
    return suma_parells(t, 0);
    }
    else return 0;
}