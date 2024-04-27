#include <iostream>
using namespace std;

int main() {
    string s;
    int c = 0;

    bool start = false;
    while (cin >> s and s != "end") {
        if (start) ++c;
        if (s == "beginning") start = true;
    }

    if (start and s == "end") cout << c << endl;
    else cout << "wrong sequence" << endl;
}