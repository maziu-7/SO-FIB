#include <iostream>
#include <vector>
using namespace std;

string exit(int p, vector<int>& v) {
	vector<bool> aux(v.size(), false);
	while (not aux[p]) {
		aux[p] = true;
		if (v[p] > 0) {
			if (p + v[p] >= aux.size()) return "right";
			p += v[p];
		} else if (v[p] < 0) {
			if (p + v[p] < 0) return "left";
			p += v[p];
		}
	}
	return "never";
}