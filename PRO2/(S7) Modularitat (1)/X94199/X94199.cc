#include "Estudiant.hh"
#include <vector>
using namespace std;

/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
   nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
   ordre que a V */
void simplificar_vector(vector<Estudiant>& v, int& pos) {
	pos = 0;
	int N = v.size();
	for(int i = 1; i < N; ++i) {
		if(v[pos].consultar_DNI() == v[i].consultar_DNI()) {
			if(v[i].te_nota()) {
				if(v[pos].te_nota()) {
					if(v[i].consultar_nota() > v[pos].consultar_nota()) {
						v[pos].modificar_nota(v[i].consultar_nota());
					}
				}
				else {
					v[pos].afegir_nota(v[i].consultar_nota());
				}
			}
		}
		else {
			++pos;
			v[pos] = v[i];
		}
	}
}