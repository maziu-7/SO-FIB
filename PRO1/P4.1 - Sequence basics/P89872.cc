#include <iostream>
using namespace std;

int main() {
    string word,largest,seclargest;

    while (cin >> word) {
        if (word > seclargest and word != largest) {
            if (word > largest) {
                seclargest = largest;
                largest = word;
            }
            else seclargest = word;
        }
    }
    cout << seclargest << endl;
}