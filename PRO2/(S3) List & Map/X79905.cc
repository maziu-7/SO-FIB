#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string,int> parties;
    string c,word;
    while (cin >> c >> word) {
        if (c == "a") ++parties[word];
        else if (c == "e" and parties[word] > 0) --parties[word];
        else if (c == "f") cout << parties[word] << endl;
    }
}