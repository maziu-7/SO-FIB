#include<iostream>
using namespace std;

int main() {
    int n1,n2,n3;
    cin >> n1 >> n2;
    
    bool greater = false;
    cin >> n3;
    while (n3 != 0) {
        if (n2 > 3143 and n1 < n2 and n3 < n2) greater = true;
        else {
            n1 = n2;
            n2 = n3;
        }
        cin >> n3;
    }
    if (greater) cout << "YES" << endl;
    else cout << "NO" << endl;
}