#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2) {
	int n = v1.size();
	int m = v2.size();
	vector<double> aux(n);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n and j < m) {
		if (v1[i] < v2[j]) {
			if (k == 0 or v1[i] != aux[k - 1]) {
				aux[k] = v1[i];
				++k;
			}
			++i;
		} else if (v1[i] > v2[j]) ++j;
		else ++i;
	}
	while (i < n) {
		if (k == 0 or v1[i] != aux[k - 1]) {
			aux[k] = v1[i];
			++k;
		}
		++i;
	}
	vector<double> diff(k);
	for (int p = 0; p < k; ++p) diff[p] = aux[p];
	return diff;
}