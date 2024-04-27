#include <iostream>
#include <list>
#include "BinTree.hh"
using namespace std;

struct codificacio {
    string s;
    string codi;
};

void i_obtenir_codis(const BinTree<string>& T, list<codificacio>& C, string cod) {
    if (not T.empty()) {
        if (T.left().empty() and T.right().empty()) {
            codificacio cf;
            cf.s = T.value();
            cf.codi = cod;
            C.insert(C.end(),cf);
        }
        else {
            i_obtenir_codis(T.left(),C,cod+"0");
            i_obtenir_codis(T.left(),C,cod+"1");
        }
    }
}

void obtenir_codis(const BinTree<string>& T, list<codificacio>& C) {
    string cod = "";
    i_obtenir_codis(T,C,cod);
}

void escriure_llista(const list<codificacio>& l) {
    list<codificacio>::const_iterator it = l.begin();
    while (it != l.end()) {
        cout << (*it).s << " " << (*it).codi << endl;
        ++it;
    }
}

int main() {
    BinTree<string> a;
    string format;
    getline(cin, format);
    a.setInputOutputFormat(format=="INLINEFORMAT"?  BinTree<string>::INLINEFORMAT  :  BinTree<string>::VISUALFORMAT);
    cin >> a;
    list<codificacio> l;
    obtenir_codis(a,l);
    escriure_llista(l);
}