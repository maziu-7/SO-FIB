#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    int i = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
    if (i < nest and vest[i].consultar_DNI() == est.consultar_DNI()) b = true;
    else b = false;
    if (not b) {
        for (int j = nest - 1; j >= i; --j) {
            vest[j+1] = vest[j];
        }
        vest[i] = est;
        ++nest;
        if (est.te_nota()) {
            ++nest_amb_nota;
            suma_notes += est.consultar_nota();
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    int i = cerca_dicot(vest, 0, nest - 1, dni);
    if (i < nest and vest[i].consultar_DNI() == dni) b = true;
    else b = false;
    if (b) {
        if (vest[i].te_nota()) {
            --nest_amb_nota;
            suma_notes -= vest[i].consultar_nota();
        }
        for (int j = i; j < nest - 1; ++j) {
            vest[j] = vest[j+1];
        }
        --nest;
    }
}