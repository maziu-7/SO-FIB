#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,num;
    cin >> n;

    vector<int> v(1001);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        num -= 1000000000;
        ++v[num];
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != 0) cout << 1000000000 + i << " : " << v[i] << endl;
    }
}