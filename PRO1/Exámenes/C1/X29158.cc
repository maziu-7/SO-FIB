#include <iostream>
using namespace std;

int main() {
    char c;
    int sum = 0;

    cin >> c;
    while (c != '.') {
        if (c >= 'A' and c <= 'Z') sum += c - 'A' + 1;
        else if (c >= 'a' and c <= 'z') sum += c -'z' - 1;
        cin >> c;
    }
    cout << sum << endl;
}
