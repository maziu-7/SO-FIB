#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    string instr;

    while (cin >> instr) {
        if (instr == "push_front") {
            int x;
            cin >> x;
            l.push_front(x);
        }
        else if (instr == "push_back") {
            int x;
            cin >> x;
            l.push_back(x);
        }
        else if (instr == "pop_front") {
            if (l.empty()) cout << "error" << endl;
            else l.pop_front();
        }
        else if (instr == "pop_back") {
            if (l.empty()) cout << "error" << endl;
            else l.pop_back();
        }
        else if (instr == "get_mid_value") {
            if (l.size() % 2 == 0) cout << "error" << endl;
            else {
                list<int>::iterator it = l.begin();
                for (int i = 0; i < l.size()/2; i++) {
                    ++it;
                }
                cout << *it << endl;
            }
        }
    }
}