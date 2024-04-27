#include <iostream>
#include "BinTreeIOParInt.hh"
using namespace std;

bool busca(BinTree<ParInt> arbre, int nivell, int n) {
    if (!arbre.empty()) {
        if (arbre.value().primer() == n) {
        cout << n << ' ' << arbre.value().segon() << ' ' << nivell << endl;
        return true;
        }
        else if (busca(arbre.left(), nivell+1, n)) return true;
        else if (busca(arbre.right(), nivell+1,n)) return true;
    }
    return false;
}

int main() {
    int n;
    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);
    while(cin >> n) {
        if (!busca(arbre, 0, n)) cout << -1 << endl;
    }
}