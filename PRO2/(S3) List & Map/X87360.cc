#include<iostream>
#include<list>
using namespace std;

void leer_lista(list<int>& l) {
    int n,x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        l.insert(l.end(),x);
    }
}

void escribir_lista(const list<int>& l) {
    list<int>::const_iterator it = l.begin();
    while (it != l.end()) {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}

void inter(list<int>& uno, const list<int>& dos) {
/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    while (it1 != uno.end()) {
        if (it2 == dos.end() or *it1 < *it2) it1 = uno.erase(it1);
        else if (*it1 == *it2) {
            ++it1;
            ++it2;
        }
        else ++it2;
    }
}