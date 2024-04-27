#include <iostream>
#include <vector>
using namespace std;

struct parint {
    int prim, seg;
};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint p;
    p.prim = p.seg = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > p.prim) p.prim = v[i];
        else if (v[i] < p.seg) p.seg = v[i];
    }
    return p;
}

pair<int, int> max_min2(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int,int> q;
    q.first = q.second = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > q.first) q.first = v[i];
        else if (v[i] < q.second) q.second = v[i];
    }
    return q;
}

void max_min3(const vector<int> &v, int &x, int &y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = y = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
}