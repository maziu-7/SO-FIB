#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string name, inst;
    while (cin >> name) {
        cin >> inst;
        if (inst == "enters") {
            if (m.find(name) == m.end()) m.insert(make_pair(name,0));
            else cout << name << " is already in the casino" << endl;
        }
        else if (inst == "leaves") {
            map<string,int>::iterator it = m.find(name);
            if (it != m.end()) {
                cout << name << " has won " << it->second << endl;
                m.erase(name);
            }
            else cout << name << " is not in the casino" << endl;
        }
        else {
            int x;
            cin >> x;
            if (m.find(name) == m.end())
                cout << name << " is not in the casino" << endl;
            else {
                map<string,int>::iterator it = m.find(name);
                int y = it->second;
                y = y + x;
                m.erase(name);
                m.insert(make_pair(name, y));
            }
        }
    }
    cout << "----------" << endl;
    for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) 
        cout << it->first << " is winning " << it->second << endl;
}