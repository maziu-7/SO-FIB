void troba(node_arbre* node, Arbre& asub, const T& x, int n, int& min) {
    if (node != NULL) {
        ++n;
        if (node->info == x and (min == -1 or n < min)) {
            asub.primer_node = copia_node_arbre(node);
            min = n;
        }
        else {
            troba(node->segE, asub, x, n, min);
            troba(node->segD, asub, x, n, min);
        }
    }
}

void sub_arrel(Arbre& asub, const T& x) {
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
    int min = -1;
    troba(primer_node, asub, x, 0, min);
}