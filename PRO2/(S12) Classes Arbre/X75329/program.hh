int i_freq(const node_arbre* node, const T& x) const {
    if (node == NULL) return 0;

    int c = 0;
    if (node->info == x) ++c;
  
    c += i_freq(node->segE, x);
    c += i_freq(node->segD, x);

    return c;
}

int freq(const T& x) const {
  /* Pre: cert */
  /* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
    return i_freq(primer_node, x);
}