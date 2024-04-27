#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> p;
    char i;
    int x;
    while (cin >> i) {
        if (i == 'A') {
            if (p.empty()) cout << "error!" << endl;
            else cout << p.top() << endl;
        }
        else if (i == 'S') {
            cin >> x;
            p.push(x);
        }
        else if (i == 'R') {
            if (not p.empty()) p.pop();
            else cout << "error!" << endl;
        }
        else if (i == 'I') {
            cin >> x;
            if (not p.empty()) {
                int y = p.top();
                y = y + x;
                p.pop();
                p.push(y);
            }
            else cout << "error!" << endl;
        }
        else {
            cin >> x;
            if (not p.empty()) {
                int y = p.top();
                y = y - x;
                p.pop();
                p.push(y);
            }
            else cout << "error!" << endl;
        }
    }
}