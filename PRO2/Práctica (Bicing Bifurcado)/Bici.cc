/** @file Bici.cc
    @brief Implementación de la clase Bici
 */
#include "Bici.hh"
using namespace std;

Bici::Bici() {}

void Bici::viaje_nuevo(const string& origen, const string& destino) {
    pair<string, string> viajes(origen, destino);
    vbicis.insert(vbicis.end(), viajes);
    estacion = destino;
}

void Bici::modificar_estacion(const string& ide) {
    estacion = ide;
}

string Bici::estacion_actual() const {
    return estacion;
}

void Bici::imprimir_viajes() {
    list<pair<string, string>>::iterator pos;
    for (pos = vbicis.begin(); pos != vbicis.end(); ++pos) {
        cout << pos->first << ' ' << pos->second << endl;
    }
}