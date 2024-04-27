#include <iostream>
#include <map>
using namespace std;

int main() {
    string inst;
    int sum = 0;
    int x;
    map<int, int> m;

    while (cin >> inst) {
        if (inst == "add") {
            cin >> x;
            ++m[x]; //afegeix 1 a les ocurrències d'x
            sum += x; //actualitza la suma del multiconjunt
        }
        else if (inst == "remove") {
            cin >> x;
            if (m[x] > 1) --m[x]; //si hi ha +1 ocurrència de x, restem 1
            else m.erase(x); //si només hi ha 1, l'eliminem
            sum -= x; //actualitzem suma
        }
        else if (inst == "occurrences") {
            cin >> x;
            if (m.find(x) != m.end()) cout << m[x] << endl;
            //si x es troba al multiconjunt, imprimeix el seu número de ocurrències
            else cout << 0 << endl;
        }
        else {
            if (m.empty()) cout << 0 << endl;
            else if (inst == "max") cout << m.rbegin()->first << endl;
            else if (inst == "min") cout << m.begin()->first << endl;
            else cout << sum << endl;
        }
    }
}