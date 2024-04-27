#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;

    if (c >= 'a' and c <= 'z') {
        cout << "lowercase" << endl;
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') cout << "vowel" << endl;
        else cout << "consonant" << endl;
    }
    else {
        cout << "uppercase" << endl;
        if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') cout << "vowel" << endl;
        else cout << "consonant" << endl; 
    }
}