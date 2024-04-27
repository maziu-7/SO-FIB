#include <iostream>
#include <vector>
using namespace std;

int fusion(vector<int>& v, int e, int m, int d) {
    vector<int> aux(d - e + 1);
    int i = e; //para recorrer v desde e hasta m
    int j = m + 1; //para recorrer v desde m+1 hasta d
    int k = 0; //para recorrer aux
    int c = 0; //para numero de inversiones
    while (i <= m and j <= d) {
        if (v[i] > v[j]) {
            aux[k++] = v[j++]; //++k, ++i
            c += m - i + 1;
        }
        else { //v[i] <= v[j]
            aux[k++] = v[i++];
        }
    }
    //si i <= m es porque acabamos la 2a parte
    while (i <= m) aux[k++] = v[i++];
    //si j <= d es porque acabamos la 1a parte
    while (j <= d) aux[k++] = v[j++];
    //copiamos aux en v
    for (int l = 0; l < aux.size(); ++l)
        v[e+l] = aux[l];

    return c;
}

int inversions(vector<int>& v, int i, int j) {
    if (i < j) {
        int m = (i+j)/2;
        int n1 = inversions(v, i, m);
        //HI1: n1 es el número de inversiones que hay entre i..m
        int n2 = inversions(v, m+1, j);
        //HI2: n2 es el número de inversiones que hay entre m+1..j
        int n3 = fusion(v, i, m, j);
        return n1 + n2 + n3;
    }
    return 0;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        cout << inversions(v, 0, n-1) << endl;
    }
}