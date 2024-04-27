#include <iostream>
using namespace std;

int main() {
    int n1,n2,n3;
    char op;
    string comp;
    
    while (cin >> n1 >> op >> n2 >> comp >> n3) {
        bool verify = false; //booleano para comprobar la operación
        int n4 = 0; //inicializamos n4
        
        if (op == '+') n4 = n1 + n2;
        else if (op == '-') n4 = n1 - n2;
        else n4 = n1*n2;
        //todos los posibles casos de comparación
        if (comp == "<") verify = (n4 < n3);
        else if (comp == ">") verify = (n4 > n3);
        else if (comp == "<=") verify = (n4 <= n3); 
        else if (comp == ">=") verify = (n4 >= n3);
        else if (comp == "==") verify = (n4 == n3);
        else verify = (n4 != n3);

        if (verify) cout << "true" << endl;
        else cout << "false" << endl;
    }
}