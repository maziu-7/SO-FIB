#include <iostream>
#include <vector>
using namespace std;

int first_rec(double x, const vector<double>& v, int i, int j) {
	if (i > j) return -1;
	if (i == j) {
		if (v[i] == x) return i;
		return -1;
	}
	int m = (i+j)/2;
	if (v[m] >= x) return first_rec(x, v, i, m);
	else return first_rec(x, v, m+1, j);
}


int first_occurrence (double x, const vector<double>& v) {
	return first_rec(x, v, 0, v.size()-1);
}

int main () {
  	int n;
  	while (cin >> n) { //num elem del vector
	  	vector<double> v(n);
	  	for (int i = 0; i < n; ++i) cin >> v[i];
	  	int t;
	  	cin >> t; //num elem que voy a pasar para buscar
	  	while (t--) {
		   double x;
	  		cin >> x;  
	  		cout << first_occurrence(x, v) << endl;
	  	}
	}
}