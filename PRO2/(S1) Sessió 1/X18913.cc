#include <iostream>
#include <vector>
using namespace std;
 
int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: si el resultado es v.size(), x no esta en v;
en caso contrario, indica la posicion de la primera aparicion de x en v */
{
    int size = v.size();
    int i = 0;
    bool found = false;
    while (i < size and not found) {
        if(v[i] == x) found = true;
        else ++i;
    }
    return i;
}