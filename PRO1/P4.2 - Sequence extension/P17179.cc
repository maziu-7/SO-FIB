#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double min = 0;
        double max = 0;
        double c = 1;
        double total = 0;
        int m;
        cin >> m;
        double x;
        cin >> x;
        max = min = total = x;
        for (int j = 1; j < m; ++j) {
            cin >> x;
            if (x > max) max = x;
            else if (x < min) min = x;
            total += x;
            ++c;
        }
        cout << min << " " << max << " " << total/c << endl; 
    }
}