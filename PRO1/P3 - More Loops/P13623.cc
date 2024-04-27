#include <iostream>
using namespace std;

int main() {
    int r,c;
    cin >> r >> c;
    int sum = 0;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char x;
            cin >> x;
            if (i%2 == 0 and j%2 == 0)
                sum += x - '0';
            else if (i%2 != 0 and j%2 != 0)
                sum += x - '0';
        }
    }
    cout << sum << endl;
}