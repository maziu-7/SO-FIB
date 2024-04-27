#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n,x;
    cin >> n;
    
    stack<int> s;

    for (int i = 0; i < n/2; ++i) {
        cin >> x;
        s.push(x);
    }
    
    if (n%2 != 0) cin >> x;
    bool palindrome = true;
    while (palindrome and not s.empty()) {
        cin >> x;
        if (x != s.top()) palindrome = false;
        s.pop();
    }
    
    if (palindrome) cout << "SI" << endl;
    else cout << "NO" << endl;
}