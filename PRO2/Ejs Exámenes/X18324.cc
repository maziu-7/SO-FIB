#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int max = 0;
        int c = 0;
        int pos = 0;
        bool error = false;
        stack<char> p;
        while (not error and pos < s.size()) {
            if (s[pos] == '(') p.push('(');
            else if (s[pos] == '[') p.push('[');
            else if (s[pos] == ')') {
                if (p.empty()) error = true;
                else if (p.top() == '[') error = true;
                else if (p.top() == '(') {
                    p.pop();
                    c += 2;
                }
            }
            else if (s[pos] == ']') {
                if (p.empty()) error = true;
                else if (p.top() == '(') error = true;
                else if (p.top() == '[') {
                    p.pop();
                    c += 2;
                }
            }
            if (not error and p.empty()) {
                if (c > max) max = c;
            }
            ++pos;
        }
        cout << max << endl;
    }
}