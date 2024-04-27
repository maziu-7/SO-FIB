#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin.ignore();

    vector<queue<string>> q(n);

    for (int i = 0; i < n; ++i) {
        string cola;
        getline(cin, cola);
        stringstream ss(cola);
        while (ss >> s) {
            q[i].push(s);
        }
    }

    cout << "DEPARTS" << endl << "-------" << endl;
    while (cin >> s) {
        if (s == "LEAVES") {
            int num_cola;
            cin >> num_cola;
            if (num_cola <= n and num_cola >= 1 and !q[num_cola-1].empty()) {
                cout << q[num_cola-1].front() << endl;
                q[num_cola-1].pop();
            }
        }
        else if (s == "ENTERS") {
            string nombre;
            int num_cola;
            cin >> nombre >> num_cola;
            if (num_cola <= n and num_cola >= 1) q[num_cola-1].push(nombre);
        }
    }
    cout << endl << "FINAL CONTENTS" << endl << "--------------" << endl;

    for (int i = 1; i <= n; ++i) {
        cout << "queue " << i << ":";
        while (!q[i-1].empty()) {
            cout << ' ' << q[i-1].front();
            q[i-1].pop();
        }
        cout << endl;
    }
}