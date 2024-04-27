#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void eliminar(stack<string>& s, int q) {
    for (int i = 0; i < q; ++i) {
        s.pop();
    }
}

void afegir(stack<string> s, int n) {
    cout << "Pila de la categoria " << n << endl;
    while (not s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main() {
    int num_cat;
    cin >> num_cat;
    
    vector<stack<string>> v(num_cat);
    
    int op;
    cin >> op;
    
    while (op != -4) {
        if (op == -1) {
            string nom;
            int n;
            cin >> nom >> n;
            v[n-1].push(nom);
        }
        else if (op == -2) {
            int q, n;
            cin >> q >> n;
            eliminar(v[n-1],q);
        }
        else if (op == -3) {
            int n;
            cin >> n;
            afegir(v[n-1],n);
        }
        cin >> op;
    }
}