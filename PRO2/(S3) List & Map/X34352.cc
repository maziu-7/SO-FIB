#include<iostream>
#include<list>
#include <map>
using namespace std;

int main() {
    map<string,int> matches;
    string c,word;
    while (cin >> c >> word) {
        if (c == "a") ++matches[word];
        else cout << matches[word] << endl;
    }
}