#include <iostream>

using namespace std;

#include "BinTree.hh"

/*
PRE: t = T. prof és la profunditat del subarbre t.
POST: Retorna un arbre d'enters R amb la mateixa estructura que T.
      Per a cada posició p de T i R, si p és a profunditat senar,
      llavors T i R tenen el mateix valor a posició p.
      En canvi, si p es a profunditat parell, llavors el valor de R a posició
      p és la suma de tots els valors que es troben a T a posició p o per sota.
      A més, suma és la suma dels nodes de t.
*/
BinTree<int> i_SumBelowAtEvenDepth(BinTree<int> t, int prof, int &suma) {
    if (t.empty()) {
        suma = 0;
        return t;
    }
    else {
        int sumae,sumad;
        BinTree<int> te = i_SumBelowAtEvenDepth(t.left(),prof+1,sumae);
        BinTree<int> td = i_SumBelowAtEvenDepth(t.right(),prof+1,sumad);
        int raiz;
        suma = sumae + sumad + t.value();
        if (prof%2 == 0) raiz = suma;
        else raiz = t.value();
        return BinTree<int>(raiz,te,td);
    }
}

BinTree<int> SumBelowAtEvenDepth(BinTree<int> t) {
    int suma;
    return i_SumBelowAtEvenDepth(t,0,suma);
}