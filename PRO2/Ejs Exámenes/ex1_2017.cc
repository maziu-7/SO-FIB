#include <iostream>
#include <list>
using namespace std;

typedef list<int> Li;
typedef list<int>::iterator It;
typedef list<int>::const_iterator CIt;

//1.1

pair<int, CIt> max_long_esc(const Li& v) {
    if (v.empty()) return make_pair(0,v.end());
    pair<int,CIt> r(1,v.begin());

    CIt it = v.begin();
    CIt itprim = v.begin();
    int cont = 1;
    int anterior = *it;
    ++it;
    while (it != v.end()) {
        if (*it >= anterior) {
            ++cont;
            if (cont > r.first) {
                r.first = cont;
                r.second = itprim;
            }
        }
        else {
            itprim = it;
            cont = 1;
        }
        anterior = *it;
        ++it;
    }
}

//1.2
/*
INV:
- it apunta a un element de v
- itprim apunta a un element de v
- cont és el nombre d'elements de l'escala que s'està tractant
- anterior és el valor de l'element anterior a l'apuntat per it
- r és un pair que el seu primer component és la longitud de l'escala màxima trobada entre v.begin()
  i l'element anterior a it. el segon component apunta al primer element d'aquesta escala màxima
*/

/*
funció fita: si n és el nombre d'elements tractats,
la funció fita seria: v.size() - n. (it != v.end())
*/ 

//1.3

void llegir(Li& v) {
    int x;
    cin >> x;
    while (x != 0) {
        v.insert(v.end(),x);
        cin >> x;
    }
}

//1.4

/*
PRE: si n > 0, it apunta a un element vàlid i a la llista
apuntada hi ha com a mínim n-1 elements posteriors a it 
POST: s'escriu al canal estàndar de sortida els n elements
consecutius des de it (inclòs)
*/ 
void escriure(CIt it, int n) {
    for (int i = 0; i < n; ++i) {
        cout << *it << endl;
        ++it;
    }
}

int main() {
    list<int> v;
    llegir(v);
    pair<int,CIt> r = max_long_esc(v);
    escriure(r.second, r.first);
}