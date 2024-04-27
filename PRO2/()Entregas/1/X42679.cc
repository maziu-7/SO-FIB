#include <iostream>
#include <list>
using namespace std;

int main() {
    string inst;
    list<pair<int, int>> l;
    pair<int, int> p (0,0);  
    //fem servir el pair de ints amb la finalitat de que al mateix temps que
    //es modifiqui la llista, actualitzem també el nombre d'elements iguals
    //i consecutius.
    while (cin >> inst) {
        int x;
        if (inst == "push_front") {
            cin >> x;
            if (not l.empty()) {
                p = *l.begin();
                if (x == p.first) {
                    ++p.second; //actualitzem max_equal_left
                    *l.begin() = p;
                }
                else {
                    p = make_pair(x,1);
                    //si x i p.first són diferents max_equal_left passa a valer 1
                    l.push_front(p);
                }
            }
            else {
                p = make_pair(x,1); //si la llista és buida afegim el primer element
                l.push_front(p);
            }
        }
        else if (inst == "push_back") {
            cin >> x;
            if (not l.empty()) {
                p = *l.rbegin();
                if (x == p.first) {
                    ++p.second; //actualitzem max_equal_right
                    *l.rbegin() = p;
                }
                else {
                    p = make_pair(x,1);
                    //si x i p.first són diferents max_equal_right passa a valer 1
                    l.push_back(p);
                }
            }
            else {
                p = make_pair(x,1); //si la llista és buida afegim el primer element
                l.push_back(p);
            }
        }
        else if (inst == "pop_front") {
            if (not l.empty()) {
                p = *l.begin();
                if (p.second > 1) { 
                    --p.second; //si max_equal_left > 1, restem 1
                    *l.begin() = p;
                }
                else {
                    l.pop_front(); //si és = 1, simplement eliminem x de la llista
                }
            }
            else cout << "error" << endl; //si és = 0, salta error
        }
        else if (inst == "pop_back") {
            if (not l.empty()) {
                p = *l.rbegin();
                if (p.second > 1) {
                    --p.second; //si max_equal_right > 1, restem 1
                    *l.rbegin() = p;
                }
                else if (p.second == 1) {
                    l.pop_back(); //si és = 1, simplement eliminem x de la llista
                }
            }
            else cout << "error" << endl; //si és = 0, salta error
        }
        else if (inst == "max_equal_left") {
            if (not l.empty()) {
                p = *l.begin();
                cout << p.second << endl;
            }
            else cout << 0 << endl;
        }
        else {
            if (not l.empty()) {
                p = *l.rbegin();
                cout << p.second << endl;
            }
            else cout << 0 << endl;
        }
    }
}