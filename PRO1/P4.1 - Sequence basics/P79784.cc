#include <iostream>
using namespace std;

int main() {
    char dir;
    int x = 0;
    int y = 0;
    while (cin >> dir) {
        if (dir == 'n') --y;
        else if (dir == 's') ++y;
        else if (dir == 'e') ++x;
        else --x;
    }
    cout << "(" << x << ", " << y << ")" << endl;
}