#include <iostream>
using namespace std;

int main() {
    char first,second,third;
    int happy_c = 0;
    int sad_c = 0;
    bool dash = false;

    cin >> first >> second;
    while (cin >> third) {
        if (third != '-') dash = false;
        if (not dash) {
            if (first == ':' and second == '-' and third == ')') ++happy_c;
            else if (first == '(' and second == '-' and third == ':') ++happy_c;
            else if (first == ':' and second == '-' and third == '(') ++sad_c;
            else if (first == ')' and second == '-' and third == ':') ++sad_c;
            first = second;
            second = third;
        }
        if (third == '-') dash = true;
    }
    cout << happy_c << " " << sad_c << endl;
}