#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {
    double aux = 0;
    for (double i = 0; i < u.size(); ++i) {
        aux += u[i]*v[i];
    }
    return aux;
}