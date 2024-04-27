/** @file Estacion.cc
    @brief Implementación de la clase Estacion
 */
#include "Estacion.hh"
using namespace std;

Estacion::Estacion() {}

Estacion::Estacion(int n) {
    capacidad = n;
    pl_estacion = n;
}

void Estacion::anadir_bici(const string& idb) {
    bicis_est.insert(idb);
    --pl_estacion;
}

void Estacion::eliminar_bici(const string& idb) {
    bicis_est.erase(idb);
    ++pl_estacion;
}

void Estacion::modificar_capacidad(int n) {
    pl_estacion += n - capacidad;
    capacidad = n;
}

bool Estacion::estacion_llena() const {
    if (pl_estacion == 0) return true;
    return false;
}

void Estacion::bicis_estacion() const {
    set<string>::iterator it = bicis_est.begin();
    while (it != bicis_est.end()) {
        cout << *it << endl;
        ++it;
    }
}

int Estacion::cantidad_bicis() const {
    return capacidad - pl_estacion;
}

int Estacion::plazas_libres() const {
    return pl_estacion;
}

string Estacion::bici_menor() const {
    return (*bicis_est.begin());
}