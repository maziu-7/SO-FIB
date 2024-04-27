/** @file Bici.hh
    @brief Especificación de la clase Bici
*/
#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/** @class Bici
    @brief Representa una bici con sus respectivos viajes
 */
class Bici {

private:
    list<pair<string, string>> vbicis; //viajes de la bici
    string estacion; //estación que ocupa la bici
                     
public:
    //Constructoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es una <em>Bici</em> sin viajes
     * \coste Constante
     */
    Bici();

    //Modificadoras

    /**
     * @brief Añade un viaje a la bici
     * \pre <em>origen</em> y <em>destino</em> existen y son diferentes
     * \post Se ha añadido un viaje al parámetro implícito
     * \coste Constante
     */
    void viaje_nuevo(const string& origen, const string& destino);

    /**
     * @brief Modifica la estación en la que se encuentra la bici
     * \pre cierto
     * \post El parámetro implícito se pasa a ser <em>ide</em>
     * \coste Constante
     */
    void modificar_estacion(const string& ide);

    //Consultoras
    
    /**
     * @brief Consultora de la estación
     * \pre cierto
     * \post El resultado es la estación en la que se encuentra la bici actualmente
     * \coste Constante
     */
    string estacion_actual() const;

    //Lectura y/o escritura

    /**
     * @brief Operación de escritura
     * \pre cierto
     * \post Se han escrito por el canal estándar de salida todos los viajes que ha hecho la bici
     * \coste Lineal
     */
    void imprimir_viajes();
};
#endif