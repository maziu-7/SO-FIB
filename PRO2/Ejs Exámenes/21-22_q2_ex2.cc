#include "BinTree.hh"

int ii_num_errores(const BinTree<int> &a, const vector<int> &v, int &i) {
    if (a.empty()) return 0;
    else {
        int n = 0;
        if (v[i] != a.value()) ++n;
        ++i;
        int e = ii_num_errores(a.left(),v,i);
        int d = ii_num_errores(a.right(),v,i);
        n += e + d;
        return n;
    }
}

int num_errores(const BinTree<int> &a, const vector<int> &v) {
    int i = 0;
    ii_num_errores(a,v,i);
}

int main() {
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BinTree<int>::INLINEFORMAT  :  BinTree<int>::VISUALFORMAT);
    cin >> t;
    vector<int> v;
    int x;
    while (cin >> x) v.push_back(x);
    int ne = num_errores(t,v);
    cout << ne << endl;
}