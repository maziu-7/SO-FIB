#include <iostream>
#include <vector>
using namespace std;

int pow(int a, int b){
    if (a == 0) return 1;
    int p = b;
    for (int i = 1; i < a; ++i){
        p *= b;
    }
    return p;
}

vector<vector<bool>> f(int n) { 
    if (n == 1){
        return vector<vector<bool>>(1, vector<bool> (1, false));
    }
    int p2 = pow(n - 1, 2);
    vector<vector<bool>> res(pow(n,2) - 1, vector<bool>(pow(n,2)-1, true));
    vector<vector<bool>> fract = f(n-1);
    for(int i = 0; i < p2 - 1; ++i){
        for(int j = 0; j < p2 - 1; ++j){
            res[i][j] = fract[i][j];
            res[i + p2][j] = fract[i][j];
            res[i][j + p2] = fract[i][j];
            res[i + p2][j + p2] = fract[i][j];
        }
    }
    res[0][p2 - 1] = false;
    res[p2 - 1][0] = false;
    res[p2 - 1][pow(n,2) - 2] = false;
    res[pow(n,2) - 2][p2 - 1] = false;
    return res;
}

void printf(vector<vector<bool>>& tabla) {
    int a = tabla.size();
    for (int i = 0; i < a; ++i){
        for(int j = 0; j < a; ++j){
            if (tabla[i][j]) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
}

int main() {
    int k;
    cin >> k;
    vector<vector<bool>>taula;
    taula = f(k);
    printf(taula);
}