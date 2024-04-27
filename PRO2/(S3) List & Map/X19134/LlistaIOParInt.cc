#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
    ParInt p;
    while (p.llegir()) l.insert(l.end(),p);
}

void EscriureLlistaParInt(const list<ParInt>& l) {
    list<ParInt>::const_iterator it = l.begin();
    while (it != l.end()) {
        it->escriure();
        ++it;
    }
}