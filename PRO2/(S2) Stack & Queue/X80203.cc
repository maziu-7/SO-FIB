#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    stack<int> p;

    while (cin >> s) {
        int size = s.size();
        int c = 1;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(') {
                p.push(c);
                cout << s[i] << p.top();
                ++c;
            }
            else if (s[i] == ')') {
                cout << s[i] << p.top();
                p.pop();
            }
        }
        cout << endl;
    }
}