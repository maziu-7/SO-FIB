#include "Estudiant.hh"
#include <vector>
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
   resultat es la posicio de l'estudiant de nota maxima de v i la segona
   component es la posicio de l'estudiant de nota minima de v (si hi ha
   empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
   hi ha cap estudiant amb nota, totes dues components valen -1 */
   pair<int,int> res(-1,-1);
   for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            if (res.first == -1) {
                res.first = i;
                res.second = i;
            }
            else {
                if (v[i].consultar_nota() > v[res.first].consultar_nota()) {
                    res.first = i;
                }
                else if (v[i].consultar_nota() == v[res.first].consultar_nota()) {
                    if (v[i].consultar_DNI() < v[res.first].consultar_DNI()) {
                        res.first = i;
                    }
                }
                if (v[i].consultar_nota() < v[res.second].consultar_nota()) {
                    res.second = i;
                }
                else if (v[i].consultar_nota() == v[res.second].consultar_nota()) {
                    if (v[i].consultar_DNI() < v[res.second].consultar_DNI()) {
                        res.second = i;
                    }
                }
            }
        }
    }
    return res;
}