#include<iostream>
#include<set>
using namespace std;

void calcular(set<string>& totes, set<string>& cap, const set<string>& act) {
    set<string>::iterator itt, itc;
    set<string>::const_iterator itact;
    itt = totes.begin();
    itact = act.begin();
    while (itact != act.end()) {
        itc = cap.find(*itact);
        if (itc != cap.end()) cap.erase(*itact);
        if (*itt < *itact) {
            itt = totes.erase(itt);
        }
        else if (*itt == *itact) {
            ++itt;
            ++itact;
        }
        else ++itact;
    }
    while (itt != totes.end()) {
        itt = totes.erase(itt);
    }
}

void llegir_set(set<string>& s) {
    string x;
    cin >> x;
    while (x !=  ".") {
        s.insert(x);
        cin >> x;
    }
}

void escriure_set(const set<string>& s) {
    set<string>::const_iterator it = s.begin();
    while (it != s.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
}

int main() {
    set<string> totes,cap;
    llegir_set(cap);
    totes = cap;
    int nact;
    cin >> nact;
    
    for (int i = 0; i < nact; ++i) {
        set<string> act;
        llegir_set(act);
        calcular(totes,cap,act);
    }
    cout << "Totes les activitats:";
    escriure_set(totes);
    cout << "Cap activitat:";
    escriure_set(cap);
}