#include <iostream>
using namespace std;

int main() {
    char c;
    bool hello = false;
    cin >> c;
    while (not hello and c != '.') {
        if (c == 'h') {
            cin >> c;
            if (c == 'e') {
                cin >> c;
                if (c == 'l') {
                    cin >> c;
                    if (c == 'l') {
                        cin >> c;
                        if (c == 'o') hello = true;
                    }
                }
            }
        }
        else cin >> c;
    }
    if (hello) cout << "hello" << endl;
    else cout << "bye" << endl;
}