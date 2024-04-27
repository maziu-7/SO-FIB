#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    if (t > 30) {
        cout << "it's hot" << endl;
        if (t >= 100) cout << "water would boil" << endl;
    }
    else if (t < 10) {
        cout << "it's cold" << endl;
        if (t <= 0) cout << "water would freeze" << endl;
    }
    else cout << "it's ok" << endl;
}