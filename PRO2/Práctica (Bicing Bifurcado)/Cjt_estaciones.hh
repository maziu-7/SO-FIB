/** @file Cjt_estaciones.hh
    @brief Especificación de la clase Cjt_estaciones
*/
#ifndef CJT_ESTACIONES_HH
#define CJT_ESTACIONES_HH

#include "Estacion.hh"
#include "Cjt_bicis.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#endif

/**
 * @class Cjt_estaciones 
 * @brief Representa todas las estaciones del sistema de Bicing
 */
class Cjt_estaciones {

private:
    BinTree<string> arbol_estaciones; //árbol en el que se encuentran todas las estaciones
    map<string, Estacion> ce; //identificadores de las estaciones junto a la información específica de cada estación
    int pl_totales = 0; //plazas libres totales entre todas las estaciones
    void i_inicializar_estaciones(BinTree<string>& a); //función inmersiva que inicializa todas las estaciones
    void i_subir_bicis(const BinTree<string>& a, Cjt_bicis& cb); //función inmersiva para subir bicis
    void i_asignar_estacion(const BinTree<string>& a, string& ide, double& coef_max, int& num_est, int& pl); //función inmersiva para asignar estación

public:
    //Constructoras

    /**
     * @brief Constructora por defecto
     * \pre cierto
     * \post El resultado es un <em>Cjt_estaciones</em> vacío
     * \coste Constante
     */
    Cjt_estaciones();

    //Modificadoras

    /**
     * @brief Da de alta una bici a una estación
     * \pre La estación <em>ide</em> existe. La bici <em>idb</em> no está en la estación y cabe en esta 
     * \post Se ha dado de alta la bici <em>idb</em> en el parámetro implícito
     * \coste Cuasilineal
     */
    void alta_bici(const string& idb, const string& ide);

    /**
     * @brief Da de baja una bici
     * \pre La bici <em>idb</em> existe
     * \post Se ha dado de baja la bici <em>idb</em> del parámetro implícito
     * \coste Logarítmico
     */
    void baja_bici(const string& idb, const string& ide);

    /**
     * @brief Mueve una bici de una estación a otra
     * \pre Tanto la estación <em>destino</em> como la bici <em>idb</em> existen, la bici <em>idb</em> cabe en <em>destino</em>
     * y las estaciones <em>origen</em> y <em>destino</em> son diferentes
     * \post Se ha movido la bici <em>idb</em> desde <em>origen</em> hasta <em>destino</em>
     * \coste Cuasilineal
     */
    void mover_bici(const string& ide, const string& idb, const string& origen);

    /**
     * @brief Altera la capacidad de una estación
     * \pre La estación <em>ide</em> existe y n > 0, n >= cantidad de bicis actual
     * \post Se ha modificado la capacidad total de la estación <em>ide</em>
     * \coste Logarítmico
     */
    void modificar_capacidad(const string& ide, int n);

    /**
     * @brief Mueve bicis a niveles superiores del conjunto
     * \pre El parámetro implícito está inicializado
     * \post Se han subido a estaciones superiores del árbol todas las bicis posibles
     * \coste Cuadrático
     */
    void subir_bicis(Cjt_bicis& cb);

    //Consultoras

    /**
     * @brief Consultora que indica si existe una estación
     * \pre El parámetro implícito está inicializado
     * \post El resultado indica si la estación <em>ide</em> existe
     * \coste Logarítmico
     */
    bool existe_estacion(const string& ide) const;

    /**
     * @brief Consultora que indica si una estación está llena
     * \pre cierto
     * \post El resultado indica si la estación <em>ide</em> está llena
     * \coste Logarítmico
     */
    bool estacion_llena(const string& ide) const;

    /**
     * @brief Consultora y escritora que indica qué bicis contiene una estación
     * \pre La estación <em>ide</em> existe
     * \post Se han escrito las bicis de la estación <em>ide</em> en el canal
     * estándar de salida
     * \coste Logarítmico
     */
    void bicis_estacion(const string& ide) const;

    /**
     * @brief Consultora de las bicis de una estación
     * \pre cierto
     * \post El resultado es el número de bicis que contiene la estación <em>ide</em>
     * \coste Logarítmico
     */
    int cantidad_bicis(const string& ide) const;

    /**
     * @brief Consultora de las plazas totales del conjunto de estaciones
     * \pre cierto
     * \post El resultado es el número de plazas totales entre todas las estaciones
     * \coste Constante
     */
    int plazas_totales() const;

    /**
     * @brief Consultora y escritora que asigna una bici a una estación
     * \pre El parámetro implícito está inicializado
     * \post Se ha añadido la bici <em>idb</em> al parámetro implícito
     * \coste Cuasilineal
     */
    void asignar_estacion(const string& idb, Cjt_bicis& b);

    //Lectura y/o escritura

    /**
     * @brief Lee los parámetros de entrada y va añadiéndolos a Cjt_estaciones
     * \pre El parámetro implícito está inicializado y vacío
     * \post Los nuevos parámetros se guardan en el conjunto de estaciones
     * \coste Lineal
     */
    void inicializar_estaciones();
};
#endif