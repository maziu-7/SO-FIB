#include <iostream>
#include <vector>
using namespace std;

bool resis_dico(double x, const vector<double>& v, int i, int j) {
	if (i > j) return false;
	int m = (i + j)/2;
	if (v[m] == x or (m < j and v[m+1] == x) or (m > i and v[m-1] == x)) return true;
	else if (v[m] > x) return resis_dico(x, v, i, m-1);
	else return resis_dico(x, v, m+1, j);
}

bool resistant_search(double x, const vector<double>& v) {
	return resis_dico(x, v, 0, v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}