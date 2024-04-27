#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c = 0;
        int first;
        cin >> first;
        while (first != 0) {
            int second,next;
            cin >> second;
            if (second > first) ++c;
            first = second;
        }
        cout << c << endl;
    }
}