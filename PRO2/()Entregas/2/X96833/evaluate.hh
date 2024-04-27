#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*,/.
//       Les operacions no produeixen errors d'overflow,
//       però poden produïr error de divisió per 0.
// Post: Si l'avaluació de l'expressió representada per t no produeix errors de divisió per 0, 
//       llavors 'result' val l'avaluació d'aquesta expressió i 'error' val 'false'.
//       En cas contrari, 'error' val 'true', i el valor de 'result' és irrellevant.
void evaluate(BinTree<string> t, int &result, bool &error);