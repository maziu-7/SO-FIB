/** @file Cjt_bicis.cc
    @brief Implementación de la clase Cjt_bicis
 */
#include "Cjt_bicis.hh"
using namespace std;

Cjt_bicis::Cjt_bicis() {}

void Cjt_bicis::anadir_bici(const string& idb, const string& ide) {
    Bici b;
    b.modificar_estacion(ide);
    cb.insert(make_pair(idb, b));
}

void Cjt_bicis::eliminar_bici(const string& idb) {
    cb.erase(idb);
}

void Cjt_bicis::viaje_nuevo(const string& origen, const string& destino, const string& idb) {
    cb[idb].viaje_nuevo(origen, destino);
}

void Cjt_bicis::modificar_estacion(const string& idb, const string& ide) {
    cb[idb].modificar_estacion(ide);
}

bool Cjt_bicis::existe_bici(const string& idb) const {
    if (cb.find(idb) == cb.end()) return false;
    return true;
}

string Cjt_bicis::estacion_bici(const string& idb) {
    return cb[idb].estacion_actual();
}

void Cjt_bicis::imprimir_viajes(const string& idb) {
    cb[idb].imprimir_viajes();
}