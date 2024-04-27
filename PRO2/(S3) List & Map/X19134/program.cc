#include <iostream>
#include "LlistaIOParInt.hh"

int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);
    int n,c,sum;
    c = sum = 0;
    cin >> n;
    list<ParInt>::iterator it = l.begin();
    while (it != l.end()) {
        if (it->primer() == n) {
            ++c;
            sum += it->segon();
        }
        ++it;
    }
    cout << n << " " << c << " " << sum << endl; 
}