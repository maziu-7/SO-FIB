#include <iostream>
#include <vector>
using namespace std;

// Pre: c1,c2,c3 are pairwise different characters.
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       s[i1]=c1, s[i2]=c2, s[i3]=c3.
int numberSubsequences(const string &s, char c1, char c2, char c3) {
    int count_c1 = 0;
    int count_c2 = 0;
    int count_c3 = 0;
    for (int i = 0; i < s.size(); ++i) {
        /**Por cada char del string sumamos los contadores, si es c1, sumamos
         * solamente c1.
         * Si es c2, acumulamos c2 con c1, ya que las nuevas posibilidades
         * de una subsecuencia son las que ya teniamos en c1 mas las de c2.
         * Lo mismo que pasa con c1 y c2, pasa con c2 y c3.
         */
        if (s[i] == c1) ++count_c1;
        else if (s[i] == c2) count_c2 += count_c1;
        else if (s[i] == c3) count_c3 += count_c2;
    }
    //Retornamos count_c3 porque es donde se acumulan todas las posibilidades totales
    //de subsecuencias entre c1, c2 y c3.
    return count_c3;
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       either s[i1]=':', s[i2]='-', s[i3]=')' or s[i1]='(', s[i2]='-', s[i3]=':'.
int numberHappySubsequences(const string &s) {
    //Retornamos la suma de los dos casos posibles de una subsecuencia feliz
    return numberSubsequences(s, ':', '-', ')') + numberSubsequences(s, '(', '-', ':');
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       either s[i1]=':', s[i2]='-', s[i3]='(' or s[i1]=')', s[i2]='-', s[i3]=':'.
int numberSadSubsequences(const string &s) {
    //Retornamos la suma de los dos casos posibles de una subsecuencia triste
    return numberSubsequences(s, ':', '-', '(') + numberSubsequences(s, ')', '-', ':');
}

int main() {
    string s;
    while (cin >> s) {
        cout << numberHappySubsequences(s) << ' ';
        cout << numberSadSubsequences(s) << endl;
    }
}