#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= 16; ++i) {
        cout << "Base " << i << ": ";
        int c = 0;
        int temp = n;
        while (temp > 0) {
            temp /= i;
            ++c;
        }
        cout << c << " cifras." << endl;
    }
}