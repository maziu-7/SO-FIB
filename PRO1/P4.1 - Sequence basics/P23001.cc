#include <iostream>
using namespace std;

int main() {
    string previous,n;
    int c = 1;
    int max = 1;

    cin >> previous;
    while (cin >> n) {
        if (previous == n) {
            ++c;
            if (max < c) max = c;
        }
        else c = 0;
    }
    cout << max << endl;
}