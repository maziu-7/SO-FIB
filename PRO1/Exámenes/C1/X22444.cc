#include <iostream>
using namespace std;

int main() {
    int n;
    bool b = false;
    while (not b and cin >> n) {
        int aux = n;
        int sum = 0;
        while (aux > 0) {
            if ((aux%10)%2 != 0) sum += (aux%10);
            aux /= 10;
        }
        if (sum%2 == 0) b = true;
    }
    if (b) cout << n << endl;
    else cout << "no impar-par" << endl;
}