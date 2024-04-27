#include <iostream>
#include <list>
using namespace std;

//1.1

/*
PRE: la llista sel està ordenada creixentment. it apunta a un element de sel

POST: el resultat és un iterador que apunta a l'element de sel davant el qual s'ha d'inserir
      x perquè sel segueixi estant creixentment ordenada.
*/
list<int>::iterator i_pos_insertar_rec(int x, list<int>& sel, list<int>::iterator it) {
    if (it == sel.end() or *it >= x) return it;
    ++it;
    return i_pos_insertar_rec(x,sel,it);
}

//1.2

list<int>::iterator pos_insertar_rec(int x, list<int>& sel) {
    return i_pos_insertar_rec(x,sel,sel.begin());
}

//1.3

void seleccionados(int n, list<int>& sel) {
    int x;
    cin >> x;
    /*
    INV: Si m és el nombre d'elements llegits de la seqüència:
            - si m <= n, sel conté m elements llegits ordenats creixentment
            - si m > n, sel conté els n elements més grans dels m elements llegits,
              ordenats creixentment.
    */
    while (x != 0) {
        bool insertar;
        list<int>:: iterator it;
        if (sel.empty()) {
            it = sel.end();
            insertar = true;
        }
        else if (sel.size() < n) {
            it = pos_insertar_rec(x,sel);
            insertar  = true;
        }
        else {
            if (*sel.begin() < x) {
                sel.erase(sel.begin());
                it = pos_insertar_rec(x,sel);
                insertar = true;
            }
            else insertar = false;
        }
        if (insertar) sel.insert(it,x);
        cin >> x;
    }
}

int main() {
    list<int> sel;
    int n;
    cin >> n;
    seleccionados(n,sel);
    list<int>::const_iterator it = sel.begin();
    while (it != sel.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
}