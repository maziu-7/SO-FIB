#include <iostream>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) {
        int sum = 0;
        cout << "suma dels cubs entre " << a << " i ";
        cout << b << ": ";
        for (int i = a; i <= b; ++i) {
            sum += i*i*i;
        }
        cout << sum << endl;
    }
}