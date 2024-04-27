int suma_aux(const node_arbre* node) const {
    if (node == NULL) return 0;
    int x = node->info;
    int e = suma_aux(node->segE);
    int d = suma_aux(node->segD);
    if (e > d) return e + x;
    return d + x;
}

T max_suma_cami() const {
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
    return suma_aux(primer_node);
}