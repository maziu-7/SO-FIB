#include <iostream>
#include <map>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    string s;
    int min = -1;
    int max = -1;
    double avg = 0;

    while (cin >> s) {
        map<int,int> m;

        if (s == "number") {
            int x;
            cin >> x;
            auto it = m.find(x);
            if (it != m.end()) ++m[x];
            else m.insert(make_pair(1, x));
            if (x > max) max = x;
            else if (x < min) min = x;
        }
        else if (s == "delete") {
            if (not m.empty()) {
                auto it = m.begin();
                int smallest;
                smallest = it->first;
                --m[smallest];
            }
        }

        if (m.empty()) cout << "no elements" << endl;
        else {
            cout << "minimum: " << min << ", ";
            cout << "maximum: " << max << ", ";
            cout << "average: " << avg << endl;
        }
    }
}