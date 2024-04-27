#include "CuaIOParInt.hh"
#include <iostream>
using namespace std;

int main() {
    queue<ParInt> ini, c1, c2;
    llegirCuaParInt(ini);
    int t1 = 0;
    int t2 = 0;
    while (not ini.empty()) {
            if (t1 <= t2) {
            c1.push(ini.front());
            t1 += ini.front().segon();
        }
        else {
            c2.push(ini.front());
            t2 += ini.front().segon();
        }
        ini.pop();
    }
    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);
}