#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string inst;
    while (cin >> inst) {
        if (inst == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                map<string,int>::iterator it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (inst == "maximum?") {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                map<string,int>::iterator it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (inst == "store") {
            string word;
            cin >> word;
            if (m.find(word) == m.end()) m.insert(make_pair(word,1));
            else ++m[word];
        }
        else {
            string word;
            cin >> word;
            if (m.find(word) != m.end()) {
                if (m[word] > 1) --m[word];
                else m.erase(word);
            }
        }
    }
}