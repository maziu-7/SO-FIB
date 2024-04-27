#include <iostream>
#include <vector>
using namespace std;

int evaluate(const vector<int>& p, int x) {
    int r = 0;

    for (int i = p.size() - 1; i >= 0; --i) {
        r = r*x + p[i];
    }
    return r;
}