/** @mainpage Bicing Bifurcado

    El programa principal se encuentra en el módulo program.cc. Teniendo en cuenta los tipos de datos sugeridos por el enunciado,
    necesitamos varios módulos: uno para representar las bicis de manera individual (Bici), uno para el conjunto de todas las bicis (Cjt_bicis),
    uno para representar las estaciones individualmente (Estacion) y uno para el conjunto de todas las estaciones (Cjt_estaciones)
    @file program.cc
    @brief Programa principal de <em>Bicing Bifurcado</em>
 */
#include "Cjt_bicis.hh"
#include "Estacion.hh"
#include "Cjt_estaciones.hh"
using namespace std;

/** @brief Ejecución del código principal de <em>Bicing Bifurcado</em>
 */
int main() {
    Cjt_estaciones ce;
    Cjt_bicis cb;
    ce.inicializar_estaciones();
    string op;
    while (cin >> op and op != "fin") {
        string idb, ide;
        if (op == "alta_bici" or op == "ab") {
            cin >> idb >> ide;
            cout << "#ab " << idb << " " << ide << endl;
            if (cb.existe_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if (not ce.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (ce.estacion_llena(ide)) cout << "error: la bici no cabe" << endl;
            else {
                cb.anadir_bici(idb,ide);
                ce.alta_bici(idb,ide);
            }
        }
        
        else if (op == "baja_bici" or op == "bb") {
            cin >> idb;
            cout << "#bb " << idb << endl;
            if (not cb.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else {
                ide = cb.estacion_bici(idb);
                cb.eliminar_bici(idb);
                ce.baja_bici(idb,ide);
            }
        }

        else if (op == "estacion_bici" or op == "eb") {
            cin >> idb;
            cout << "#eb " << idb << endl;
            if (not cb.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else cout << cb.estacion_bici(idb) << endl;
        }

        else if (op == "viajes_bici" or op == "vb") {
            cin >> idb;
            cout << "#vb " << idb << endl;
            if (not cb.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else cb.imprimir_viajes(idb);
        }

        else if (op == "mover_bici" or op == "mb") {
            cin >> idb >> ide;
            cout << "#mb " << idb << ' ' << ide << endl;
            if (not ce.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (not cb.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else if (cb.estacion_bici(idb) == ide) cout << "error: la bici ya esta en el sitio" << endl;
            else if (ce.estacion_llena(ide)) cout << "error: la bici no cabe" << endl;
            else {
                string origen = cb.estacion_bici(idb);
                ce.mover_bici(ide, idb, origen);
                cb.viaje_nuevo(origen, ide, idb);
            }
        }

        else if (op == "bicis_estacion" or op == "be") {
            cin >> ide;
            cout << "#be " << ide << endl;
            if (not ce.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else ce.bicis_estacion(ide);
        }

        else if (op == "modificar_capacidad" or op == "mc") {
            int n;
            cin >> ide >> n;
            cout << "#mc " << ide << ' ' << n << endl;
            if (not ce.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if (ce.cantidad_bicis(ide) > n) cout << "error: capacidad insuficiente" << endl;
            else ce.modificar_capacidad(ide, n);
        }

        else if (op == "plazas_libres" or op == "pl") {
            cout << "#pl" << endl;
            cout << ce.plazas_totales() << endl;
        }

        else if (op == "subir_bicis" or op == "sb") {
            cout << "#sb" << endl;
            ce.subir_bicis(cb);
        }

        else if (op == "asignar_estacion" or op == "ae") {
            cin >> idb;
            cout << "#ae " << idb << endl;
            if (cb.existe_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if (ce.plazas_totales() == 0) cout << "error: no hay plazas libres" << endl;
            else {
                ce.asignar_estacion(idb, cb);
                cout << cb.estacion_bici(idb) << endl;
            }
        }
    }
}