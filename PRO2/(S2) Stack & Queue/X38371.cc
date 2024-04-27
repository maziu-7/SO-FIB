#include <iostream>
#include <queue>
using namespace std;

void min_max(queue<int> q, int& min, int& max) {
    min = max = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() < min) min = q.front();
        else if (q.front() > max) max = q.front();
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n,min,max;
    cin >> n;
    double sum = 0;
    min = max = n;

    while (n <= 1000 and n >= -1001) {
        if (n != -1001) {
            if (n < min) min = n;
            if (n > max) max = n;
            sum += n;
            q.push(n);
        }
        else if (!q.empty()) {
            int prev = q.front();
            sum -= prev;
            q.pop();
            if (!q.empty() and (min == prev or max == prev)) min_max(q, min, max);
        }
        if (q.empty()) {
            min = 1001;
            max = -1001;
            sum = 0;
            cout << 0;
        }
        else cout << "min " << min << "; max " << max << "; media " << sum/q.size();
        cout << endl;
        cin >> n;
    }
}