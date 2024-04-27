#include<iostream>
using namespace std;

char encoded(char c, int k) {
    char enc;
    
    if (c >= 'a' and c <= 'z')
        enc = 'A' + (c - 'a' + k)%('z' - 'a' + 1);
    else if (c == '_') enc = ' ';
    else enc = c;

    return char(enc);
}

int main() {
    char c;
    int k;
    while (cin >> k) {
        cin >> c;
        while (c != '.') {
            cout << encoded(c,k);
            cin >> c;
        }
        cout << endl;
    }
}