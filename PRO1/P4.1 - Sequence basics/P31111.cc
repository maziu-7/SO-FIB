#include<iostream>
using namespace std;

int main() {
    char a;
    int c = 0;
    while (c >= 0 and cin >> a) {
        if (a == '(') ++c;
        else --c;
    }
    if (c == 0) cout << "yes" << endl;
    else cout << "no" << endl;
}