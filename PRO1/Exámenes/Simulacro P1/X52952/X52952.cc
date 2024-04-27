#include <iostream>
using namespace std;

int main() {
    int n,m,side;
    while (cin >> n >> m >> side) {
        int gridHeight = n*(side + 1) + 1;
        int gridWidth = m*(side + 1) + 1;
        for (int i = 0; i < gridHeight; i++) {
            for (int j = 0; j < gridWidth; j++) {
                if (i%(side + 1) == 0 or j%(side + 1) == 0) {
                    cout << "#";
                }
                else cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}