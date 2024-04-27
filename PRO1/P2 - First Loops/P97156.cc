#include <iostream>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;

    for (int i = x; i <= y; ++i) {
        if (i != y) cout << i << ",";
        else cout << y;
    }
    cout << endl; 
}