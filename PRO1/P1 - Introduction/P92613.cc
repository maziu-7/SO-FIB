#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;
    
    if (double(x) == int(x)) cout << int(x) << ' ' << int(x) << ' ' << int(x) << endl;
    else cout << int(x) << ' ' << int(x) + 1 << ' ' << int(x + 0.5) << endl; 
}