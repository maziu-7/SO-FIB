#include <iostream>
#include <vector>
using namespace std;

int common_elements(const vector<int>& X, const vector<int>& Y) {
    int c = 0;
    int i = 0;
    int j = 0;
    int a = X.size();
    int b = Y.size();
    while (i < a and j < b) {
        if (X[i] == Y[j]) {
            ++c;
            ++i;
            ++j;
        }
        else if (X[i] > Y[j]) ++j;
        else ++i;
    }
    return c;
}