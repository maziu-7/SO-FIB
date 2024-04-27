#include <iostream>
using namespace std;

void print_line(char c, string s, bool b) {
    cout << s << "('" << c << "') = ";
    if (b) cout << "true" << endl;
    else cout << "false" << endl;
}

int main () {
    char c;
    cin >> c;
    
    bool letter = ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'));
    bool upper = (c >= 'A' and c <= 'Z');
    bool vowel = (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c== 'u');
    bool digit = (c >= '0' and c <= '9');
    
    if (upper) {
        c -= 'A';
        c += 'a';
        vowel = (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c== 'u');
        c += 'A';
        c -= 'a';
    }
    
    print_line(c, "letter", letter);
    print_line(c, "vowel", vowel);
    print_line(c, "consonant", (letter and not vowel));
    print_line(c, "uppercase", upper);
    print_line(c, "lowercase", (not upper and letter));
    print_line(c, "digit", digit);
}