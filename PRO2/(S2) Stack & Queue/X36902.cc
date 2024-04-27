#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    bool error = false;
    char c;
    int t = 1;
    cin >> c;
    
    while (not error and c != '.') {
        if (c == '(') s.push(1);
        else if (c == '[') s.push(2);
        else if (c == ')') {
            if (!s.empty() and s.top() == 1) s.pop();
            else {
                cout << "Incorrecte " << t << endl;
                error = true;
            }
        }
        else if (c == ']') {
            if (!s.empty() and s.top() == 2) s.pop();
            else {
                cout << "Incorrecte " << t << endl;
                error = true;
            }
        }
        cin >> c;
        ++t;
    }
    if (not error and s.empty()) cout << "Correcte" << endl;
    else if (not s.empty() and not error) cout << "Incorrecte " << t-1 << endl;
}